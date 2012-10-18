#ifndef STAGE_HPP
#define STAGE_HPP

#include <gamelib/ResourceLoader.hpp>
#include <gamelib/Perspective.hpp>

class Stage {
	bool loaded;
public:
	Stage()
	{
		
	}

	virtual ~Stage() {
		if (IsLoaded()) {
			Unload();
		}
	}

	virtual void Load() {
		loaded = true;
	}

	virtual void Unload() {
		loaded = false;
	}

	virtual bool IsLoaded() {
		return loaded;
	}

	virtual ResourceLoader &GetResources() = 0;
	virtual Perspective &GetPerspective() = 0;
	virtual void Update() = 0;
	virtual void Draw() const = 0;
};

#endif /* STAGE_HPP */

