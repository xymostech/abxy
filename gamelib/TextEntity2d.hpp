#ifndef TEXTENTITY2D_HPP
#define TEXTENTITY2D_HPP

#include <gamelib/TextEntity.inl>

class TextEntity2d : public TextEntity, public Entity2d {
	
public:
	TextEntity2d(long type,
	             std::string font_name,
	             const Vector2& position = Vector2(),
	             const Vector2& velocity = Vector2(),
	             float angle = 0,
	             float angvelocity = 0);
	virtual ~TextEntity2d();

	virtual void Update();

	virtual void Draw(Matrix4 model_matrix) const;
};

#endif /* TEXTENTITY2D_HPP */

