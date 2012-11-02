#ifndef STAGE_INL
#define STAGE_INL

#include <gamelib/Stage.hpp>

Stage::Stage()
{
	
}

Stage::~Stage() {
	if (IsLoaded()) {
		Unload();
	}
}

void Stage::Load() {
	loaded = true;
}

void Stage::Unload() {
	loaded = false;
}

bool Stage::IsLoaded() {
	return loaded;
}

#endif /* STAGE_INL */

