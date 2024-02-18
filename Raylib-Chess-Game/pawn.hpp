#include <raylib.h>

struct PAWN_DATA
{
	int x;
	int y;
	int type;
};

class Pawn
{
	public:
		Pawn();
		~Pawn();
		void Draw();
		void Update();

	private:
		PAWN_DATA pawns[16];
};