#include <gamelib/Game.inl>
#include <gamelib/WorldStage.inl>
#include <gamelib/Entity2d.inl>
#include <gamelib/Key.inl>
#include <gamelib/Texture.inl>
#include <gamelib/ProjectionOrtho2d.inl>

#include <gamelib/Sprite.inl>
#include <gamelib/Primitive.inl>

#include <memory>

#include <iostream>

class MyPlayer : public Entity2d {
	float direction;
	int flip_cooldown;
	Sprite sprite;
public:
	MyPlayer(float y)
	: Entity2d(0, Vector2(0, y), Vector2(1, 0), 0, 0)
	, direction(1)
	, flip_cooldown(10)
	, sprite("test.png")
	{
	}

	virtual void Register(World *world) {
		sprite.Register(world);
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

		sprite.Draw(model_matrix);
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
