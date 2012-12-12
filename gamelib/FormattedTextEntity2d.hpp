#ifndef FORMATTEDTEXTENTITY2D_HPP
#define FORMATTEDTEXTENTITY2D_HPP

#include <gamelib/Entity2d.inl>
#include <gamelib/FormattedTextEntity.inl>

class FormattedTextEntity2d : public FormattedTextEntity, public Entity2d {
protected:
	FormattedTextEntity2d(std::string font_name,
	                      const Vector2& position = Vector2(),
	                      const Vector2& velocity = Vector2(),
	                      float angle = 0,
	                      float angvelocity = 0);
public:
	FormattedTextEntity2d(long type,
	                      std::string font_name,
	                      const Vector2& position = Vector2(),
	                      const Vector2& velocity = Vector2(),
	                      float angle = 0,
	                      float angvelocity = 0);
	virtual ~FormattedTextEntity2d();

	virtual void Update();

	virtual void Draw(Matrix4 model_matrix) const;
};

#endif /* FORMATTEDTEXTENTITY2D_HPP */

