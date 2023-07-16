#include "Monster.h"
#include <iostream>
using namespace std;

void	Monster::PrintInfo()
{
	cout << "--------------------" << endl;
	cout << "[Monster Status] " << "HP: " << _hp << " ATT: " << _attack << " DEF: " << _defence << endl;
	cout << "--------------------" << endl;
}
