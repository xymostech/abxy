#include <iostream>

#include <abxy/Game.hpp>
#include <abxy/entity/ProjectionEntity.hpp>
#include <abxy/projection/ProjectionFrustum.hpp>
#include <abxy/entity/LoaderEntity.hpp>
#include <abxy/entity/WorldEntity.hpp>
#include <abxy/entity/Entity3d.hpp>
#include <abxy/primitive/Primitive.hpp>
#include <abxy/Model.hpp>

class MyEntity : public Entity3d {
	Model model;
	float time;
public:
	MyEntity()
	: MessageReceiver("myentity")
	, model("res/test.model")
	, time(0)
	{
	}

	virtual void OnLoad(LoadData &data) override {
		model.OnLoad(data);
	}

	virtual void OnUnload() override {
		model.OnUnload();
	}

	virtual void Update() override {
		time += 0.03;
	}

	virtual void Draw(Matrix4 model_matrix) const override {
		model_matrix.Rotate(Vector3(0, 1, 0), time);
		model_matrix.Translate(Vector3(1.5, 0, -5.0));

		model.Draw(model_matrix);
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
