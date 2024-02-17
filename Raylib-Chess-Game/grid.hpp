#include <raylib.h>

#define GRID_AMOUNT 8
#define GRID_SIZE 80

struct GRID_DATA
{
	int x;
	int y;
	Color color;
};

class Grid
{
	public:
		Grid();
		~Grid();
		void Draw(int id);
		void Update(int id);

	private:
		GRID_DATA grid[64];

		Color red = Color{ 255, 141, 133, 255 };
		Color yellow = Color{ 255, 241, 133, 255 };
		Color green = Color{ 157, 255, 133, 255 };
};