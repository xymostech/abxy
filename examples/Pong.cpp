#include <abxy/Game.hpp>
#include <abxy/WorldStage.hpp>
#include <abxy/Entity2d.hpp>
#include <abxy/Key.hpp>
#include <abxy/Texture.hpp>
#include <abxy/ProjectionOrtho2d.hpp>

#include <abxy/Sprite.hpp>
#include <abxy/Primitive.hpp>

#include <abxy/Font.hpp>
#include <abxy/FormattedTextEntity2d.hpp>
#include <abxy/audio/Sound.hpp>

#include <memory>
#include <iostream>

class Paddle : public Entity2d {
	Sprite sprite;

	bool left;
public:
	Paddle(bool left)
	: MessageReceiver("paddle")
	, Entity(2)
	, Entity2d(Vector2(left ? -39 : 39, 0), Vector2(), 0, 0)
	, sprite("res/white.png")
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
		model_matrix.Translate(Vector3(Position().x, Position().y, 0));
		model_matrix.Scale(Vector3(2, 10, 1));

		sprite.Draw(model_matrix);
	}

	bool IsLeft() const {
		return left;
	}
};

class Ball : public Entity2d {
	Sprite sprite;

	std::shared_ptr<Sound> sound;
public:
	Ball()
	: MessageReceiver("ball")
	, Entity(1)
	, Entity2d(Vector2(0, 0), Vector2(1, 1))
	, sprite("res/white.png")
	{
		
	}

	virtual void Register(World *world) {
		sound = world->GetParentStage()->GetSoundLoader()->Load("res/hit.ogg");

		sprite.Register(world);
		Entity2d::Register(world);
	}

	void VFlip() {
		SetVelocity(Vector2(Velocity().x, -1 * Velocity().y));
		if (Position().x < 40 && Position().x > -40) {
			sound->Play(0.5);
		}
	}

	void HFlip(float pos) {
		Vector2 newvel;
		newvel.x = -6 * (Velocity().x < 0 ? -1 : 1);
		newvel.y = -1 * pos;
		newvel.Normalize();
		SetVelocity(newvel * sqrt(2));
		sound->Play(0.5);
	}

	virtual void Update() {
		if (Position().x <= -50) {
			SetPosition(Vector2(-30, 0));
			Vector2 newvel;
			newvel.x = 1;
			newvel.y = Velocity().y * -1;
			newvel.Normalize();
			SetVelocity(newvel * sqrt(2));
			SendMessage("../score", "addright", std::shared_ptr<int>());
		}

		if (Position().x >= 50) {
			SetPosition(Vector2(30, 0));
			Vector2 newvel;
			newvel.x = -1;
			newvel.y = Velocity().y * -1;
			newvel.Normalize();
			SetVelocity(newvel * sqrt(2));
			SendMessage("../score", "addleft", std::shared_ptr<int>());
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
		model_matrix.Translate(Vector3(Position().x, Position().y, 0));
		model_matrix.Scale(Vector3(2, 2, 1));

		sprite.Draw(model_matrix);
	}
};

class Score : public FormattedTextEntity2d {
	int left_score, right_score;
public:
	Score()
	: MessageReceiver("score")
	, Entity(3)
	, FormattedTextEntity2d("res/LiberationMono-Regular.ttf", Vector2(-5, 20))
	, left_score(0)
	, right_score(0)
	{
		Format() << Formatter::Store(left_score) << "  "
		         << Formatter::Store(right_score);
	}

	virtual void ReceiveMessage(std::string id, Message m) {
		if (id == "addleft") {
			left_score++;
		} else if (id == "addright") {
			right_score++;
		}
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
		GetWorld()->Add<Ball>();
		GetWorld()->Add<Paddle>(true);
		GetWorld()->Add<Paddle>(false);
		GetWorld()->Add<Score>();
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
