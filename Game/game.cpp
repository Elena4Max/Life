#include "game.h"
#include "view.h"
#include "world.h"
#include <unistd.h>

/* Ширина игрового поля */
#define __WORLD_HEIGHT__ 10

/* Высота игрового поля */
#define __WORLD_WIDTH__ 10

Game & Game::Instance()
{
	static Game g;
	return g;
}

Game::Game() : v(View::Instance()), live_points(-1), is_optimal(false)
{}


Game::~Game()
{}


void Game::next_generation(World &world, World &prev_world)
{
	unsigned int i, j;
	unsigned int live_nb;

	for (i = 0; i < __WORLD_WIDTH__; i++) {
		for (j = 0; j < __WORLD_HEIGHT__; j++) {
			live_nb = prev_world.count_live_neighbors(i, j);
			if (prev_world.get_is_live(i, j) == 0) {
				if (live_nb == 3) {
					world.set_is_live(i, j, 1);
				}
			} else {
				if (live_nb < 2 || live_nb > 3) {
					world.set_is_live(i, j, 0);
				}
			}
		}
		
	}
}

bool Game::cmp_world(World w1, World w2)
{
	if(w1 != w2) {
		return false;
	} else {
		return true;
	}
}


void Game::run()
{

	do {
		v.print_world(world);
		prev_world = world;
		next_generation(world, prev_world);
		is_optimal = cmp_world(world, prev_world);
		live_points = world.get_live_count();

		if (is_optimal) {
		    std::cout << "Optimal configuration detected" << std::endl;
		}

		if (live_points == 0) {
		    std::cout << "All points died" << std::endl;
		}
		usleep(1000);
	} while (live_points != 0 && !is_optimal);

}
