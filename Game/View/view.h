#pragma once
#include "world.h"
#include <iostream>

class View
{

public:
	static View & Instance();
	void print_world(World);
	View(View const&) = delete;
	View & operator = (View const&) = delete;
private:

	View();
	~View();
};
