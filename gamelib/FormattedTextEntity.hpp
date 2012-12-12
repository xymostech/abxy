#ifndef FORMATTEDTEXTENTITY_HPP
#define FORMATTEDTEXTENTITY_HPP

#include <gamelib/Entity.inl>

#include <gamelib/Formatter.inl>

class FormattedTextEntity : virtual public Entity {
	Formatter format;
	std::shared_ptr<Font> font;

	std::string font_file;
protected:
	FormattedTextEntity(std::string font_file);
public:
	FormattedTextEntity(long type, std::string font_file);
	virtual ~FormattedTextEntity();

	virtual void Register(World *world);

	virtual Formatter &Format();

	virtual void Update();
	virtual void Draw(Matrix4 model_matrix) const;
};

#endif /* FORMATTEDTEXTENTITY_HPP */

