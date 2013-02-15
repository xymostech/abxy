#include <abxy/TextEntity.hpp>

#include <abxy/WorldStage.hpp>

TextEntity::TextEntity(std::string font_file, std::string text, int size)
: TextEntity(0, font_file, text, size)
{
	
}

TextEntity::TextEntity(long type, std::string font_file, std::string text, int size)
: MessageReceiver("entity")
, Entity(type)
, font_file(font_file)
, text(text)
, size(size)
{
	
}

TextEntity::~TextEntity() {
	
}

void TextEntity::Register(World *world) {
	font = world->GetParentStage()->GetFontLoader()->Load(font_file);
	font->Register(world);
}

void TextEntity::Draw(Matrix4 model_matrix) const {
	font->DrawString(text, size, model_matrix);
}

void TextEntity::SetText(std::string new_text) {
	text = new_text;
}

void TextEntity::SetSize(int new_size) {
	size = new_size;
}

