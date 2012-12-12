#ifndef FORMATTEDTEXTENTITY_INL
#define FORMATTEDTEXTENTITY_INL

#include <gamelib/FormattedTextEntity.hpp>

FormattedTextEntity::FormattedTextEntity(std::string font_file)
: FormattedTextEntity(0, font_file)
{
	
}

FormattedTextEntity::FormattedTextEntity(long type, std::string font_file)
: MessageReceiver("entity")
, Entity(type)
, font_file(font_file)
{
	
}

FormattedTextEntity::~FormattedTextEntity() {
	
}

void FormattedTextEntity::Register(World *world) {
	font = world->GetParentStage()->GetFontLoader()->Load(font_file);
	font->Register(world);
}

Formatter &FormattedTextEntity::Format() {
	return format;
}

void FormattedTextEntity::Update() {
	
}

void FormattedTextEntity::Draw(Matrix4 model_matrix) const {
	font->DrawString(format.Format(), 6, model_matrix);
}

#endif /* FORMATTEDTEXTENTITY_INL */

