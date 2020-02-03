#include "view.h"
/* Ширина игрового поля */
#define __WORLD_HEIGHT__ 10

/* Высота игрового поля */
#define __WORLD_WIDTH__ 10

View::View()
{}

View::~View()
{}
/*
 * Вывести на экран игровое поле
 */

void View::print_world(World w)
{
	#ifdef WINDOWS
	  	system("cls");
	#else
	  	system("clear");
	#endif
	unsigned int i, j;
	for (i = 0; i < __WORLD_WIDTH__; i++) {
		for (j = 0; j < __WORLD_HEIGHT__; j++) {
			if (w.get_is_live(i, j)) {
				std::cout << '*';
			} else {
				std::cout << ' ';
			}
		std::cout << ' ';
		}
		std::cout << std::endl;
	}
}

View & View::Instance()
{
	static View v;
	return v;
}

