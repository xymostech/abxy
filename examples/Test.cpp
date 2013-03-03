#include <iostream>

#include <abxy/Game.hpp>
#include <abxy/entity/WorldEntity.hpp>
#include <abxy/entity/Entity3d.hpp>

int main() {
	Game test_game(60);
	test_game.Startup();

	while (test_game.IsOpen()) {
		test_game.Update();

		test_game.Draw();
	}

	return 0;
}
