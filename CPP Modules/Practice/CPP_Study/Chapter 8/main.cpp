#include <iostream>
using namespace std;
#include "Game.h"

int	main(void)
{
	srand((unsigned int)time(NULL));
	Game	game;
	game.Init();

	while (true)
	{
		game.Update();
	}

	return (0);
}
