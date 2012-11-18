#ifndef STAGE_INL
#define STAGE_INL

#include <gamelib/Stage.hpp>

Stage::Stage()
: MessageReceiver("stage")
{
	
}

Stage::~Stage() {
	if (IsLoaded()) {
		Unload();
	}
}

void Stage::Load(Game *p) {
	loaded = true;
	parent = p;
}

void Stage::Unload() {
	loaded = false;
}

bool Stage::IsLoaded() const {
	return loaded;
}

Game *Stage::GetParentGame() const {
	return parent;
}

#endif /* STAGE_INL */

