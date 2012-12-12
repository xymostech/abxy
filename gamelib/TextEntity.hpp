#ifndef TEXTENTITY_HPP
#define TEXTENTITY_HPP

#include <gamelib/Entity.inl>
#include <string>

class TextEntity : virtual public Entity {
	std::shared_ptr<Font> font;

	std::string font_file;

	std::string text;
	int size;
protected:
	TextEntity(std::string font_file, std::string text = "", int size = 6);
public:
	TextEntity(long type, std::string font_file, std::string text = "", int size = 6);
	virtual ~TextEntity();

	virtual void Register(World *world);

	virtual void Draw(Matrix4 model_matrix) const;

	virtual void SetText(std::string new_text);
	virtual void SetSize(int new_size);
};

#endif /* TEXTENTITY_HPP */

