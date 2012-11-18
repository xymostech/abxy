#include <gamelib/Game.inl>
#include <gamelib/WorldStage.inl>
#include <gamelib/Entity2d.inl>
#include <gamelib/Key.inl>
#include <gamelib/ProjectionOrtho2d.inl>
#include <gamelib/Sprite.inl>
#include <gamelib/TextEntity2d.inl>

#include <memory>
#include <iostream>

class Paddle : public Entity2d {
	Sprite sprite;

	bool left;
public:
	Paddle(bool left)
	: Entity(2)
	, Entity2d(Vector2(left ? -39 : 39, 0), Vector2(), 0, 0)
	, sprite("white.png")
	, left(left)
	{
		
	}

	virtual void Register(World *world) {
		sprite.Register(world);
		Entity2d::Register(world);
	}

	virtual void Update() {
		if (Position().y >= -24) {
			if ((!left && Key::IsKeyPressed('M')) ||
			    ( left && Key::IsKeyPressed('Z'))) {
				SetPosition(Position() - Vector2(0, 1));
			}
		}

		if (Position().y <= 24) {
			if ((!left && Key::IsKeyPressed('K')) ||
			    ( left && Key::IsKeyPressed('A'))) {
				SetPosition(Position() + Vector2(0, 1));
			}
		}
		Entity2d::Update();
	}

	virtual void Draw(Matrix4 model_matrix) const {
		model_matrix.Scale(Vector3(2, 10, 1));
		model_matrix.Translate(Vector3(Position().x, Position().y, 0));

		sprite.Draw(model_matrix);
	}

	bool IsLeft() const {
		return left;
	}
};

class Ball : public Entity2d {
	Sprite sprite;

	int left_score, right_score;

	std::shared_ptr<TextEntity2d> score;
public:
	Ball()
	: Entity(1)
	, Entity2d(Vector2(0, 0), Vector2(1, 1))
	, sprite("white.png")
	, left_score(0)
	, right_score(0)
	{
		
	}

	virtual void Register(World *world) {
		sprite.Register(world);
		Entity2d::Register(world);

		score = std::make_shared<TextEntity2d>(
			3, "LiberationMono-Regular.ttf",
			Vector2(-5, 20)
		);

		score->Format() << Formatter::Store(left_score) << "  "
		               << Formatter::Store(right_score);

		world->AddEntity(
			std::dynamic_pointer_cast<Entity>(score)
		);
	}

	void VFlip() {
		SetVelocity(Vector2(Velocity().x, -1 * Velocity().y));
	}

	void HFlip(float pos) {
		Vector2 newvel;
		newvel.x = -6 * (Velocity().x < 0 ? -1 : 1);
		newvel.y = -1 * pos;
		newvel.Normalize();
		SetVelocity(newvel * sqrt(2));
	}

	virtual void Update() {
		if (Position().x <= -50) {
			SetPosition(Vector2(-30, 0));
			Vector2 newvel;
			newvel.x = 1;
			newvel.y = Velocity().y * -1;
			newvel.Normalize();
			SetVelocity(newvel * sqrt(2));
			right_score++;
		}

		if (Position().x >= 50) {
			SetPosition(Vector2(30, 0));
			Vector2 newvel;
			newvel.x = -1;
			newvel.y = Velocity().y * -1;
			newvel.Normalize();
			SetVelocity(newvel * sqrt(2));
			left_score++;
		}

		for (std::shared_ptr<Entity> entity : GetParentWorld()->GetEntities()) {
			if (entity->GetType() == 2) {
				std::shared_ptr<Paddle> paddle(std::dynamic_pointer_cast<Paddle>(entity));

				if (abs(paddle->Position().y - Position().y) < 6) {
					if (paddle->IsLeft() &&
					    Position().x <= -38 &&
					    Position().x >= -40 &&
					    Velocity().x < 0) {
						HFlip(paddle->Position().y - Position().y);
					}
					if (!paddle->IsLeft() &&
					    Position().x >= 38 &&
					    Position().x <= 40 &&
					    Velocity().x > 0) {
						HFlip(paddle->Position().y - Position().y);
					}
				}
			}
		}

		if ((Position().y <= -30 && Velocity().y < 0) ||
		    (Position().y >=  30 && Velocity().y > 0)) {
			VFlip();
		}

		Entity2d::Update();
	}

	virtual void Draw(Matrix4 model_matrix) const {
		model_matrix.Scale(Vector3(2, 2, 1));
		model_matrix.Translate(Vector3(Position().x, Position().y, 0));

		sprite.Draw(model_matrix);
	}
};

class MyStage : public WorldStage {
public:
	MyStage()
	: MessageReceiver("stage")
	, WorldStage(std::shared_ptr<Projection>(new ProjectionOrtho2d()))
	{
		
	}

	virtual ~MyStage() {
		
	}

	virtual void Load(Game *p) {
		GetWorld()->AddEntity(
			std::shared_ptr<Entity>(new Ball())
		);
		GetWorld()->AddEntity(
			std::shared_ptr<Entity>(new Paddle(true))
		);
		GetWorld()->AddEntity(
			std::shared_ptr<Entity>(new Paddle(false))
		);
		WorldStage::Load(p);
	}
};

class PongGame : public Game {
public:
	PongGame()
	: MessageReceiver("pong")
	, Game(120)
	{
		
	}
};

int main(int argc, char *argv[]) {
	PongGame myGame;
	myGame.Startup();

	MyStage stage;
	myGame.SetStage(&stage);

	while(myGame.IsOpen()) {
		myGame.Update();

		myGame.Draw();
	}

	return 0;
}
