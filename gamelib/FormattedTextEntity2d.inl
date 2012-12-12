#ifndef FORMATTEDTEXTENTITY2D_INL
#define FORMATTEDTEXTENTITY2D_INL

#include <gamelib/FormattedTextEntity2d.hpp>

FormattedTextEntity2d::FormattedTextEntity2d(std::string font_name,
                                             const Vector2& position,
                                             const Vector2& velocity,
                                             float angle,
                                             float angvelocity)
: FormattedTextEntity2d(0, font_name, position, velocity, angle, angvelocity)
{
	
}

FormattedTextEntity2d::FormattedTextEntity2d(long type,
                                             std::string font_name,
                                             const Vector2& position,
                                             const Vector2& velocity,
                                             float angle,
                                             float angvelocity)
: MessageReceiver("entity")
, Entity(type)
, FormattedTextEntity(font_name)
, Entity2d(position, velocity, angle, angvelocity)
{
	
}

FormattedTextEntity2d::~FormattedTextEntity2d()
{
	
}

void FormattedTextEntity2d::Update() {
	Entity2d::Update();
}

void FormattedTextEntity2d::Draw(Matrix4 model_matrix) const {
	Entity2d::Transform(model_matrix);

	FormattedTextEntity::Draw(model_matrix);
}

#endif /* FORMATTEDTEXTENTITY2D_INL */

