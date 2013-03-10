#include <iostream>

#include <abxy/Game.hpp>
#include <abxy/entity/ProjectionEntity.hpp>
#include <abxy/ProjectionIdentity.hpp>
#include <abxy/entity/LoaderEntity.hpp>
#include <abxy/entity/WorldEntity.hpp>
#include <abxy/entity/Entity3d.hpp>

class MyEntity : public Entity3d {
public:
	MyEntity()
	: MessageReceiver("myentity")
	{
	}

	virtual void Draw(Matrix4 model_matrix) const override {
		(void)model_matrix;
	}
};

int main() {
	Game test_game(60);
	test_game.Startup();

	WorldEntity world;
	ProjectionEntity<ProjectionIdentity> proj(world);
	LoaderEntity loader(proj);

	world.Add<MyEntity>();

	while (test_game.IsOpen()) {
		test_game.Update();

		test_game.Draw();
	}

	return 0;
}
