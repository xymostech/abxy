#ifndef TEXTENTITY_INL
#define TEXTENTITY_INL

#include <gamelib/TextEntity.hpp>

TextEntity::TextEntity(std::string font_file)
: TextEntity(0, font_file)
{
	
}

TextEntity::TextEntity(long type, std::string font_file)
: Entity(type)
, font_file(font_file)
{
	
}

TextEntity::~TextEntity() {
	
}

void TextEntity::Register(World *world) {
	font = world->GetParentStage()->GetFontLoader()->Load(font_file);
	font->Register(world);
}

Formatter &TextEntity::Format() {
	return format;
}

void TextEntity::Update() {
	
}

void TextEntity::Draw(Matrix4 model_matrix) const {
	font->DrawString(format.Format(), 6, model_matrix);
}

#endif /* TEXTENTITY_INL */

