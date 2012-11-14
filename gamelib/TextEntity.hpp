#ifndef TEXTENTITY_HPP
#define TEXTENTITY_HPP

#include <gamelib/Entity.inl>

#include <gamelib/Formatter.inl>

class TextEntity : virtual public Entity {
	Formatter format;
	std::shared_ptr<Font> font;

	std::string font_file;
protected:
	TextEntity(std::string font_file);
public:
	TextEntity(long type, std::string font_file);
	virtual ~TextEntity();

	virtual void Register(World *world);

	virtual Formatter &Format();

	virtual void Update();
	virtual void Draw(Matrix4 model_matrix) const;
};

#endif /* TEXTENTITY_HPP */

