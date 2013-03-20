#include <abxy/primitive/TexturePrimitive.hpp>

#include <abxy/WorldStage.hpp>

void TexturePrimitive::SetupTexture() {
	program->Use();
	texture->BindSampler(sampler_loc);
	program->Unuse();
}

void TexturePrimitive::InnerDraw() const {
	blend_style_loc.Set1i(1);

	texture->Use();
}

TexturePrimitive::TexturePrimitive(std::string program_name,
                                   std::string texture_name)
: Primitive(program_name)
, texture_name(texture_name)
{
	
}

TexturePrimitive::~TexturePrimitive() {
	
}

void TexturePrimitive::AddVertices(const std::vector<float> &verts) {
	AddAttrib("position", 4, verts);
}

void TexturePrimitive::AddTextureCoords(const std::vector<float> &texture) {
	AddAttrib("texcoord", 2, texture);
}

void TexturePrimitive::Register(World *world) {
	Primitive::Register(world);

	blend_style_loc = program->GetUniformLocation("blend_style");
	sampler_loc = program->GetUniformLocation("textureSampler");
	texture = world->GetParentStage()->GetTextureLoader()->Load(texture_name);
	SetupTexture();
}

