#include <iostream>

#include <abxy/Game.hpp>
#include <abxy/entity/ProjectionEntity.hpp>
#include <abxy/projection/ProjectionFrustum.hpp>
#include <abxy/entity/LoaderEntity.hpp>
#include <abxy/entity/WorldEntity.hpp>
#include <abxy/entity/Entity3d.hpp>
#include <abxy/Primitive.hpp>

class MyEntity : public Entity3d {
	Primitive prim;
public:
	MyEntity()
	: MessageReceiver("myentity")
	, prim("res/standard.program")
	{
		prim.AddAttrib("position", 4, {
			-0.75, -0.75, 0, 1.0,
			-0.75,  0.75, 0, 1.0,
			 0.75, -0.75, 0, 1.0,
			 0.75,  0.75, 0, 1.0,
		});

		prim.AddAttrib("color", 4, {
			1, 1, 1, 1,
			1, 1, 1, 1,
			1, 1, 1, 1,
			1, 1, 1, 1,
		});

		prim.AddIndices({
			0, 1, 2,
			2, 1, 3,
		});
	}

	virtual void OnLoad(LoadData &data) override {
		prim.OnLoad(data);
	}

	virtual void OnUnload() override {
		prim.OnUnload();
	}

	virtual void Draw(Matrix4 model_matrix) const override {
		model_matrix.Translate(Vector3(-0.15, 0, 0));

		prim.DrawAll(model_matrix);
	}
};

int main() {
	Game test_game(60);
	test_game.Startup();

	WorldEntity world;
	ProjectionEntity<ProjectionFrustum> proj(world);
	LoaderEntity loader(proj);

	world.Add<MyEntity>();

	test_game.GetBase()->SetChild(&loader);

	while (test_game.IsOpen()) {
		test_game.Update();

		test_game.Draw();
	}

	return 0;
}
