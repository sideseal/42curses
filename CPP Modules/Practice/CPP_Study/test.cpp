#include <iostream>
using namespace std;

void	many(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
	int result = a + b + c + d + e + f + g + h + i + j + k;
	cout << result << endl;
}

void	setHp(int* hp)
{
	*hp = 100;
	return ;
}

int	main()
{
	int	hp = 3;

	many(1, 2, hp, 4, 5, 6, 7, 8, 9, 10, 11);
	setHp(&hp);
	return (0);
}
