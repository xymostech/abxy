#include <abxy/FormattedTextEntity.hpp>

FormattedTextEntity::FormattedTextEntity(std::string font_file, int size)
: FormattedTextEntity(0, font_file, size)
{
	
}

FormattedTextEntity::FormattedTextEntity(long type, std::string font_file, int size)
: MessageReceiver("entity")
, Entity(type)
, TextEntity(font_file, "", size)
{
	
}

FormattedTextEntity::~FormattedTextEntity() {
	
}

Formatter &FormattedTextEntity::Format() {
	return format;
}

void FormattedTextEntity::Update() {
	SetText(format.Format());
}

