#include <abxy/Font.hpp>

#include <abxy/Exceptions.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

void Font::Load(std::string file) {
	FT_Library library;
	FT_Error error;
	FT_Face face;
	
	error = FT_Init_FreeType(&library);
	if (error) {
		throw std::runtime_error("Error initializeing freetype");
	}

	error = FT_New_Face(library, file.c_str(), 0, &face);
	if (error) {
		throw FileLoadError(std::string("Error reading font: ") + file);
	}

	error = FT_Set_Pixel_Sizes(face, 0, 64);
	if (error) {
		throw FileLoadError(
			"Error setting font sizes for: " + file
		);
	}

	std::vector<char> chars = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
		'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
		'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
		's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3',
		'4', '5', '6', '7', '8', '9', '0', '!', '@', '#', '$',
		'%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[',
		'{', ']', '}', ';', ':', '"', ',', '<', '.', '>', '/',
		'?', '`', '~', '\'', '\\', ' ',
	};

	int max_width = 0, max_height = 0;
	for (char c : chars) {
		FT_UInt index = FT_Get_Char_Index(face, c);

		error = FT_Load_Glyph(face, index, FT_LOAD_RENDER);
		if (error) {
			throw FileLoadError(
				std::string("Error loading character '") +
				c + "' from file: " + file
			);
		}

		if (face->glyph->metrics.width > max_width) {
			max_width = face->glyph->metrics.width;
		}
		if (face->glyph->metrics.height > max_height) {
			max_height = face->glyph->metrics.height;
		}
	}

	max_width /= 64;
	max_height /= 64;

	char_width = max_width;
	char_height = max_height;

	buffer_height = buffer_width = 1;
	while (buffer_height < max_height * chars.size()) {
		buffer_height <<= 1;
	}
	while (buffer_width < max_width) {
		buffer_width <<= 1;
	}

	unsigned char buffer[buffer_height * buffer_width];

	memset(buffer, 0, sizeof(buffer));

	int char_num = 0;

	std::vector<float> verts;
	std::vector<float> texcoords;

	for (char c : chars) {
		FT_UInt index = FT_Get_Char_Index(face, c);

		FT_Load_Glyph(face, index, FT_LOAD_RENDER);

		for (int i = 0; i < face->glyph->bitmap.rows; ++i) {
			unsigned char *set_buffer =
				buffer +
				char_num * buffer_width * max_height +
				i * buffer_width;
			for (int j = 0; j < face->glyph->bitmap.width; ++j) {
				set_buffer[j] =
					face->glyph->bitmap.buffer
					   [i * face->glyph->bitmap.width + j];
			}
		}

		CharData &data = char_data[c];

		data.char_offset = char_num;
		data.width = face->glyph->metrics.width / 64;
		data.height = face->glyph->metrics.height / 64;
		data.bearing_x = face->glyph->metrics.horiBearingX / 64;
		data.bearing_y = face->glyph->metrics.horiBearingY / 64;
		data.advance = face->glyph->metrics.horiAdvance / 64;

		float v[16] = {
			0,                 0,                   0, 1,
			(float)data.width, 0,                   0, 1,
			0,                 -(float)data.height, 0, 1,
			(float)data.width, -(float)data.height, 0, 1
		};

		float t[8] = {
			0,                 0,
			(float)data.width, 0,
			0,                 (float)data.height,
			(float)data.width, (float)data.height
		};

		verts.insert(verts.end(), std::begin(v), std::end(v));
		texcoords.insert(texcoords.end(), std::begin(t), std::end(t));

		char_num++;
	}

	std::vector<unsigned int> indices = {
		0, 1, 2,
		2, 1, 3
	};

	AddAttrib("position", 4, verts);
	AddAttrib("texcoord", 2, texcoords);
	AddIndices(indices);

	tex.Load(buffer, buffer_width, buffer_height, GL_RED);

	tex.Parameteri(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	tex.Parameteri(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void Font::InnerDraw() const {
	tex.Use();
}

Font::Font(std::string file)
: Primitive("res/font")
{
	Load(file);
}

void Font::DrawChar(char c, float size, Matrix4 model_matrix) const {
	const CharData &data = char_data.at(c);

	model_matrix.Translate(Vector3(
		size * data.bearing_x / (float)char_height,
		size * data.bearing_y / (float)char_height, 0
	));
	model_matrix.Scale(Vector3(
		size / (float)char_height,
		size / (float)char_height, 1
	));

	program->Use();

	tex_offset_loc.Set2i(0, char_height * data.char_offset);

	program->Unuse();

	DrawAllBase(model_matrix, 4 * data.char_offset);
}

void Font::DrawString(const std::string &s, float size, Matrix4 model_matrix) const {
	for (char c : s) {
		if (char_data.count(c) > 0) {
			DrawChar(c, size, model_matrix);

			const CharData &data = char_data.at(c);
			model_matrix.Translate(Vector3(
				size * data.advance / (float)char_height, 0, 0
			));
		}
	}
}

void Font::Register(World *world) {
	Primitive::Register(world);

	GLUniformRef sampler_ref = program->GetUniformLocation("textureSampler");
	tex.BindSampler(sampler_ref);

	tex_size_loc = program->GetUniformLocation("texture_size");

	program->Use();
	tex_size_loc.Set2i(buffer_width, buffer_height);
	program->Unuse();

	tex_offset_loc = program->GetUniformLocation("texture_offset");
}

