#include <iostream>
using namespace std;
#include <iomanip>

const int	MAX = 100;
int	board[MAX][MAX] = {};
int	N;

void	printBoard(void)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
};

bool	canGo(int y, int x)
{
	if (y < 0 || y >= N)
		return false;
	if (x < 0 || x >= N)
		return false;
	if (board[y][x] != 0)
		return false;
	return true;
}

void	setBoard(void)
{
	int dir = RIGHT;
	int num = 1;
	int y = 0;
	int x = 0;

	int dy[] = {0, 1, 0, -1};
	int dx[] = {1, 0, -1, 0};

	while (true)
	{
		board[y][x] = num;
		if (num == N * N)
			break;
		int nextY = y + dy[dir];
		int nextX = x + dx[dir];
		if (canGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
			dir = (dir + 1) % 4;
	}
}

int	main()
{
	cin >> N;

	setBoard();
	printBoard();
	return (0);
}
