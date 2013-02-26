#ifndef FONT_HPP
#define FONT_HPP

#include <abxy/GL/GLTextureRef.hpp>
#include <abxy/Primitive.hpp>
#include <abxy/Texture.hpp>

#include <map>

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

	void DrawChar(char c, float size, Matrix4 model_matrix) const;
	void DrawString(const std::string &s, float size, Matrix4 model_matrix) const;

	//void Register(World *world);
};

#endif /* FONT_HPP */

