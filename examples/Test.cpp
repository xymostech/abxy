#include <gamelib/Game.inl>
#include <gamelib/WorldStage.inl>
#include <gamelib/Entity2d.inl>
#include <gamelib/Key.inl>
#include <gamelib/Texture.inl>
#include <gamelib/ProjectionOrtho2d.inl>

#include <gamelib/Primitive.inl>

#include <memory>

#include <iostream>

class MyPlayer : public Entity2d {
	float direction;
	int flip_cooldown;
	Primitive prim;
public:
	MyPlayer(float y)
	: Entity2d(0, Vector2(0, y), Vector2(1, 0), 0, 0)
	, direction(1)
	, flip_cooldown(10)
	, prim("standard")
	{
		float varray[] = {
			0.0, 0.0, 0.0, 1.0,
			1.0, 0.0, 0.0, 1.0,
			0.0, 1.0, 0.0, 1.0,
			1.0, 1.0, 0.0, 1.0
		};

		std::vector<float> verts(std::begin(varray), std::end(varray));

		float carray[] = {
			1.0, 1.0, 1.0, 1.0,
			1.0, 1.0, 1.0, 1.0,
			1.0, 1.0, 1.0, 1.0,
			1.0, 1.0, 1.0, 1.0
		};

		std::vector<float> colors(std::begin(carray), std::end(carray));

		float tcoordarray[] = {
			0.0, 0.0,
			1.0, 0.0,
			0.0, 1.0,
			1.0, 1.0
		};

		std::vector<float> tcoords(std::begin(tcoordarray), std::end(tcoordarray));

		unsigned int iarray[] = {
			0, 1, 2,
			2, 1, 3
		};

		std::vector<unsigned int> indices(std::begin(iarray), std::end(iarray));

		prim.AddVertices(verts)
		    .AddColors(colors)
		    .AddTexture(tcoords)
		    .AddIndices(indices)
		    .UseTexture("test.png")
		    .Setup();
	}

	virtual void Register(World *world) {
		prim.Register(world);
		Entity2d::Register(world);
	}

	void Flip() {
		if (direction > 0) {
			direction = -1;
		} else {
			direction = 1;
		}
		SetVelocity(Vector2(direction, 0));
	}

	virtual void Update() {
		if (Position().x < -40 || Position().x > 40) {
			Flip();
		}

		if (Key::IsKeyPressed('A') && flip_cooldown == 0) {
			Flip();
			flip_cooldown = 10;
		}
		if (flip_cooldown > 0) {
			--flip_cooldown;
		}

		Entity2d::Update();
	}

	virtual void Draw(Matrix4 model_matrix) const {
		model_matrix.Scale(Vector3(3, 3, 3));
		model_matrix.Rotate(Vector3(0, 0, 1), Position().x / 40.0 * M_PI);
		model_matrix.Translate(Vector3(Position().x, Position().y, 0));

		prim.Draw(model_matrix);
	}
};

class MyStage : public WorldStage {
public:
	MyStage() :
	WorldStage(std::shared_ptr<Projection>(new ProjectionOrtho2d()))
	{
		
	}

	virtual ~MyStage() {
		
	}

	virtual void Load(Game *p) {
		GetWorld()->AddEntity(
			std::shared_ptr<Entity>(new MyPlayer(-20))
		);
		GetWorld()->AddEntity(
			std::shared_ptr<Entity>(new MyPlayer(20))
		);

		WorldStage::Load(p);
	}
};

int main(int argc, char *argv[]) {
	class Game myGame(120);
	myGame.Startup();

	MyStage stage;

	myGame.SetStage(&stage);

	while(myGame.IsOpen()) {
		myGame.Update();

		myGame.Draw();
	}

	return 0;
}
