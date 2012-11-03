#include <gamelib/Game.inl>
#include <gamelib/WorldStage.inl>
#include <gamelib/Entity2d.inl>
#include <gamelib/Key.inl>
#include <gamelib/Texture.inl>
#include <gamelib/ProjectionOrtho2d.inl>

#include <gamelib/FileLoader.inl>

#include <gamelib/Primitive.inl>

#include <memory>

#include <iostream>

class Paddle : public Entity2d {
	Primitive prim;

	bool left;
public:
	Paddle(bool left)
	: Entity2d(2, Vector2(left ? -39 : 39, 0), Vector2(), 0, 0)
	, prim("standard")
	, left(left)
	{
		float varray[] = {
			-1.0, -1.0, 0.0, 1.0,
			 1.0, -1.0, 0.0, 1.0,
			-1.0,  1.0, 0.0, 1.0,
			 1.0,  1.0, 0.0, 1.0
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
		    .AddIndices(indices)
		    .Setup();
	}

	virtual void Register(World *world) {
		prim.Register(world);
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
		model_matrix.Scale(Vector3(1, 5, 1));
		model_matrix.Translate(Vector3(Position().x, Position().y, 0));

		prim.Draw(model_matrix);
	}

	bool IsLeft() const {
		return left;
	}
};

class Ball : public Entity2d {
	Primitive prim;
public:
	Ball()
	: Entity2d(1, Vector2(0, 0), Vector2(1, 1), 0, 0)
	, prim("standard")
	{
		float varray[] = {
			-1.0, -1.0, 0.0, 1.0,
			 1.0, -1.0, 0.0, 1.0,
			-1.0,  1.0, 0.0, 1.0,
			 1.0,  1.0, 0.0, 1.0
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
		    .AddIndices(indices)
		    .UseTexture("test.png")
		    .Setup();
	}

	virtual void Register(World *world) {
		prim.Register(world);
		Entity2d::Register(world);
	}

	void VFlip() {
		SetVelocity(Vector2(Velocity().x, -1 * Velocity().y));
	}

	void HFlip(float pos) {
		Vector2 newvel;
		newvel.x = -6 * Velocity().x;
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
		}

		if (Position().x >= 50) {
			SetPosition(Vector2(30, 0));
			Vector2 newvel;
			newvel.x = -1;
			newvel.y = Velocity().y * -1;
			newvel.Normalize();
			SetVelocity(newvel * sqrt(2));
		}

		auto end = GetParentWorld()->GetEntities().end();
		for (auto it = GetParentWorld()->GetEntities().begin(); it != end; ++it) {
			if ((*it)->GetType() == 2) {
				std::shared_ptr<Paddle> paddle(std::dynamic_pointer_cast<Paddle>(*it));

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

int main(int argc, char *argv[]) {
	class Game myGame(120);
	myGame.Startup();

	FileLoader f("standard.vertex.shader");

	MyStage stage;

	myGame.SetStage(&stage);

	while(myGame.IsOpen()) {
		myGame.Update();

		myGame.Draw();
	}

	return 0;
}
