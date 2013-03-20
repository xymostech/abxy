#include <abxy/primitive/SpriteAnimation.hpp>

SpriteAnimation::SpriteAnimation(const std::vector<std::string> &v) {
	for (auto &s : v) {
		sprites.push_back(std::make_shared<Sprite>(s));
	}
}

SpriteAnimation::~SpriteAnimation() {
	
}

void SpriteAnimation::Register(World *world) {
	for (auto &sp : sprites) {
		sp->Register(world);
	}
}

void SpriteAnimation::Draw(int sprite, Matrix4 &matrix) const {
	sprites.at(sprite)->Draw(matrix);
}

int SpriteAnimation::Size() const {
	return sprites.size();
}

