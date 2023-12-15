#include "Arrow.h"
#include "Player.h"
#include <iostream>
using namespace std;

Arrow::Arrow(Player* target, int damage) 
	: _target(target), _damage(damage)
{

}

Arrow::~Arrow()
{

}

void Arrow::AttackTarget()
{
	cout << "Arrow attacked target!" << endl;

	// ���� ����� �ִٸ�
	if (_target != 0)
	{
		// �������� ������
		_target->AddHp(-_damage);
		_target->PrintInfo();
	}
}
