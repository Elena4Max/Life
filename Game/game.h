#pragma once
#include "view.h"
#include "world.h"
class Game
{

	public:
		static Game & Instance();
		Game(Game const&) = delete;
		Game & operator = (Game const&) = delete;
		void run();
	private:
		Game();
		~Game();
		/*
		 * Сгенерировать следующее поколение игрового мира
		 */
		void next_generation(World&, World&);
		/*
		 * Сравнение игровых миров текущего и предыдущего поколения
		 */
		bool cmp_world(World, World);
		View& v;
		World world;
		World prev_world;
		unsigned int live_points;
		bool is_optimal;
};

