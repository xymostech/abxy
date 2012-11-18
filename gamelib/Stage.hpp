#ifndef STAGE_HPP
#define STAGE_HPP

#include <gamelib/Projection.inl>

#include <gamelib/messages/Message.hpp>

class Game;

class Stage : virtual public MessageReceiver {
	bool loaded;

	Game *parent;
public:
	Stage();
	virtual ~Stage() = 0;

	virtual void Load(Game *p);
	virtual void Unload();
	bool IsLoaded() const;

	virtual void Update() = 0;
	virtual void Draw() const = 0;

	Game *GetParentGame() const;
};

#endif /* STAGE_HPP */

