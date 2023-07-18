#include <iostream>
using namespace std;

template<typename T>
class RandomBox
{
public:
	RandomBox()
	{
		for (int i = 0; i < 10; i++)
			_data[i] = i;
	}

	T GetRandomData()
	{
		int idx = rand() % 10;
		return _data[idx];
	}

public:
	T _data[10];
};

int	main(void)
{
	srand(static_cast<unsigned int>(time(nullptr)));

	RandomBox	<int>r1;
	RandomBox	<float>r2;
	int a = r1.GetRandomData();
	float b = r2.GetRandomData();
	cout << a << endl;
	cout << b << endl;
	return (0);
}
