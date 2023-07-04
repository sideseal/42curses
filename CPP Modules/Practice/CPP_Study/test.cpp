#include <iostream>
using namespace std;

int add(int a, int b)
{
	int result = a + b;
	return (result);
}

float add(float a, float b)
{
	float result = a + b;
	return (result);
}

int add(int a)
{
	int result = a + 1;
	return (result);
}

int	main()
{
	int	a = 3;
	int	b = 5;
	float c = 1.5f;
	float d = 2.1f;
	int result1 = add(a, b);
	float result2 = add(c, d);
	int result3 = add(a);

	cout << result1 << ", " << result2 << ", " << result3 << endl;
	return (0);
}
