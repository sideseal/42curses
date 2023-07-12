#include <iostream>
using namespace std;

class Position
{
	public:
		Position operator+(const Position& arg)
		{
			Position pos;

			pos._x = _x + arg._x;
			pos._y = _y + arg._y;
			return (pos);
		}

		bool operator==(const Position& arg)
		{
			return (_x == arg._x && _y == arg._y);
		}
		void operator=(int arg)
		{
			_x = arg;
			_y = arg;
		}

	public:
		int	_x;
		int	_y;
};

int	main(void)
{

	Position	pos1;

	pos1._x = 1;
	pos1._y = 1;

	Position	pos2;
	
	pos2._x = 2;
	pos2._y = 2;

	Position	pos3 = pos1 + pos2;
	cout << pos3._x << " " << pos3._y << endl;
	
	Position	pos5;
	pos3 = (pos5 = 5);
	return (0);
}
