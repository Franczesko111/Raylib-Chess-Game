#include <raylib.h>
#include "grid.hpp"

class Game
{
	public:
		Game();
		~Game();
		void Draw();
		void Update();

	private:
		Grid grid;
};