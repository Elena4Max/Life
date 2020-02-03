#include <random>
#include "world.h"

#define __WORLD_HEIGHT__ 10
#define __WORLD_WIDTH__ 10



World::World() : world(__WORLD_WIDTH__, std::vector<point> (__WORLD_HEIGHT__))
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> dis(1, 10000);

	unsigned int i, j;
	for (i = 0; i < __WORLD_WIDTH__; i++) {
		for (j = 0; j < __WORLD_HEIGHT__; j++) {
			unsigned int num = dis(gen);
			if (num % 2 == 0) {
				world[i][j].is_live = 1;
			} else {
				world[i][j].is_live = 0;
			}
		}
	}	
}
World::~World()
{

}
World& World::operator = (const World &w) 
{
	unsigned int i, j;
	for (i = 0; i < __WORLD_WIDTH__; i++) {
		for (j = 0; j < __WORLD_HEIGHT__; j++) {
			this->world[i][j].is_live = w.world[i][j].is_live;
		}
	}
}

bool World::operator != (World &w) const
{
	unsigned i, j;
	for (i = 0; i < __WORLD_WIDTH__; i++) {
		for (j = 0; j < __WORLD_HEIGHT__; j++) {
			if(this->world[i][j].is_live != w.world[i][j].is_live) {
				return true;
			}
		}
	}
	return false;
}

bool World::operator == (World &w) const
{
	unsigned i, j;
	for (i = 0; i < __WORLD_WIDTH__; i++) {
		for (j = 0; j < __WORLD_HEIGHT__; j++) {
			if(this->world[i][j].is_live != w.world[i][j].is_live) {
				return false;
			}
		}
	}
	return true;
}

unsigned int World::get_live_count()
{
	unsigned int count = 0;
	unsigned i, j;
	for (i = 0; i < __WORLD_WIDTH__; i++) {
		for (j = 0; j < __WORLD_HEIGHT__; j++) {
			if (this->world[i][j].is_live == 1) {
				count++;
			}
		}
	}
	return count;
}

void World::read_point_neighbors(signed int nb[][2], unsigned int x, unsigned int y)
{
	unsigned int i, j;
	unsigned int k = 0;

	for (i = x - 1; i <= x + 1; i++) {
		for (j = y - 1; j <= y + 1; j++) {
			if (i == x && j == y) {
				continue;
			}
			nb[k][0] = i;
			nb[k][1] = j;
			k++;
		}
	}
}

unsigned int World::count_live_neighbors(unsigned int x, unsigned int y)
{
	unsigned int count = 0;
	unsigned int i;
	signed int nb[8][2];
	signed int _x, _y;

	read_point_neighbors(nb, x, y);

	for (i = 0; i < 8; i++) {
		_x = nb[i][0];
		_y = nb[i][1];

		if (_x < 0 || _y < 0) {
			continue;		
		}
		if (_x >= __WORLD_WIDTH__ || _y >= __WORLD_HEIGHT__) {
			continue;
		}

		if (this->world[_x][_y].is_live == 1) {
			count++;
		}
	}

	return count;
}

bool World::get_is_live(unsigned int x, unsigned int y)
{
	return this->world[x][y].is_live;
}
void World::set_is_live(unsigned int x, unsigned int y, unsigned int l)
{
	this->world[x][y].is_live = l;
}

