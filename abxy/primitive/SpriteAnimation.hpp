#ifndef SPRITEANIMATION_HPP
#define SPRITEANIMATION_HPP

#include <vector>

#include <abxy/primitive/Sprite.hpp>

class SpriteAnimation {
	std::vector<std::shared_ptr<Sprite>> sprites;
public:
	SpriteAnimation(const std::vector<std::string> &v);
	virtual ~SpriteAnimation();

	virtual void Register(World *world);
	virtual void Draw(int sprite, Matrix4 &matrix) const;

	int Size() const;
};

#endif /* SPRITEANIMATION_HPP */

