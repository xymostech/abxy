#ifndef WORLDSTAGE_HPP
#define WORLDSTAGE_HPP

#include <memory>

#include <abxy/Stage.hpp>
#include <abxy/World.hpp>
#include <abxy/Projection.hpp>

class WorldStage : public Stage {
	World world;

	std::shared_ptr<Projection> projection;
public:
	WorldStage(std::shared_ptr<Projection> projection);
	virtual ~WorldStage();

	virtual void Draw() const;
	virtual void Update();

	std::shared_ptr<Projection> GetProjection();
	World *GetWorld();
};

#endif /* WORLDSTAGE_HPP */

