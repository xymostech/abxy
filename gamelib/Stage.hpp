#ifndef STAGE_HPP
#define STAGE_HPP

#include <gamelib/Projection.inl>

class Stage {
	bool loaded;
public:
	Stage();
	virtual ~Stage();

	virtual void Load();
	virtual void Unload();
	virtual bool IsLoaded();

	virtual Projection &GetProjection() = 0;
	virtual void Update() = 0;
	virtual void Draw() const = 0;
};

#endif /* STAGE_HPP */

