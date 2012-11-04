#ifndef TEXTUREPRIMITIVE_HPP
#define TEXTUREPRIMITIVE_HPP

#include <vector>

#include <gamelib/Primitive.inl>

#include <gamelib/Texture.inl>

class TexturePrimitive : public virtual Primitive {
	std::string texture_name;

	GLUniformRef blend_style_loc, sampler_loc;
	std::shared_ptr<Texture> texture;

	void SetupTexture();
protected:
	virtual void InnerDraw() const;
public:
	TexturePrimitive(std::string program_name, std::string texture_name);
	virtual ~TexturePrimitive();

	void AddVertices(const std::vector<float> &verts);
	void AddTextureCoords(const std::vector<float> &texture);

	virtual void Register(World *world);
};

#endif /* TEXTUREPRIMITIVE_HPP */

