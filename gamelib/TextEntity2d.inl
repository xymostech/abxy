#ifndef TEXTENTITY2D_INL
#define TEXTENTITY2D_INL

#include <gamelib/TextEntity2d.hpp>

TextEntity2d::TextEntity2d(long type,
                           std::string font_name,
                           const Vector2& position,
                           const Vector2& velocity,
                           float angle,
                           float angvelocity)
: Entity(type)
, TextEntity(font_name)
, Entity2d(position, velocity, angle, angvelocity)
{
	
}

TextEntity2d::~TextEntity2d()
{
	
}

void TextEntity2d::Update() {
	Entity2d::Update();
}

void TextEntity2d::Draw(Matrix4 model_matrix) const {
	Entity2d::Transform(model_matrix);

	TextEntity::Draw(model_matrix);
}

#endif /* TEXTENTITY2D_INL */

