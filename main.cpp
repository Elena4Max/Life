// original in https://code-live.ru/post/cpp-life-game/
#include "game.h"

int main()
{	
	Game &g = Game::Instance();
	g.run();
	return 0;
}
