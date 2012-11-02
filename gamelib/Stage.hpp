#ifndef STAGE_HPP
#define STAGE_HPP

#include <gamelib/Projection.inl>

class Game;

class Stage {
	bool loaded;

	Game *parent;
public:
	Stage();
	virtual ~Stage();

	virtual void Load(Game *p);
	virtual void Unload();
	bool IsLoaded() const;

	virtual void Update() = 0;
	virtual void Draw() const = 0;

	Game *GetParentGame() const;
};

#endif /* STAGE_HPP */

