#ifndef FONT_HPP
#define FONT_HPP

#include <gamelib/GL/GLTextureRef.inl>
#include <gamelib/Primitive.inl>

#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H

struct CharData {
	int char_offset;
	int width, height;
	int bearing_x, bearing_y;
	int advance;
};

class Font : protected Primitive {
	std::map<char, CharData> char_data;

	int char_height, char_width;
	int buffer_height, buffer_width;

	GLUniformRef tex_size_loc, tex_offset_loc;

	Texture tex;

	void Load(std::string file);
protected:
	virtual void InnerDraw() const;
public:
	Font(std::string file);

	void DrawChar(char c, int size, Matrix4 model_matrix) const;
	void DrawString(const std::string &s, int size, Matrix4 model_matrix) const;

	void Register(World *world);
};

#endif /* FONT_HPP */

