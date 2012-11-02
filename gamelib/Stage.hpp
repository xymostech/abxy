#ifndef STAGE_HPP
#define STAGE_HPP

#include <gamelib/ResourceLoader.inl>
#include <gamelib/Perspective.inl>

class Stage {
	bool loaded;
public:
	Stage();
	virtual ~Stage();

	virtual void Load();
	virtual void Unload();
	virtual bool IsLoaded();

	virtual ResourceLoader &GetResources() = 0;
	virtual Perspective &GetPerspective() = 0;
	virtual void Update() = 0;
	virtual void Draw() const = 0;
};

#endif /* STAGE_HPP */

