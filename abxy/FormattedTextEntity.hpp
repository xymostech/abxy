#ifndef FORMATTEDTEXTENTITY_HPP
#define FORMATTEDTEXTENTITY_HPP

#include <abxy/TextEntity.hpp>

#include <abxy/Formatter.hpp>

class FormattedTextEntity : public TextEntity {
	Formatter format;
protected:
	FormattedTextEntity(std::string font_file, int size = 6);
public:
	FormattedTextEntity(long type, std::string font_file, int size = 6);
	virtual ~FormattedTextEntity();

	virtual Formatter &Format();

	virtual void Update();
};

#endif /* FORMATTEDTEXTENTITY_HPP */

