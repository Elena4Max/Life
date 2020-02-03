#pragma once
#include <vector>

class World
{
	public:
		World();
		~World();
		World& operator = (const World&);
		bool operator != (World&) const;
		bool operator == (World&) const;
		unsigned int get_live_count();
		void read_point_neighbors(signed int nb[][2], unsigned int x, unsigned int y);
		unsigned int count_live_neighbors(unsigned int x, unsigned int y);
		bool get_is_live(unsigned int x, unsigned int y);
		void set_is_live(unsigned int x, unsigned int y, unsigned int l);

		struct point {
			unsigned is_live:1;
		};
	private:
		std::vector< std::vector<point> > world;
};

