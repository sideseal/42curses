#include "Archer.h"
#include "Pet.h"

Archer::Archer()
{
	// �̷� ���� ���� ä�� ����~
	_pet = new Pet();
}

Archer::Archer(int hp) : Player(hp)
{
	// �̷� ���� ���� ä�� ����~
	_pet = new Pet();
}

Archer::~Archer()
{
	// ��ſ��� �� �� :(
	if (_pet != 0)
		delete _pet;
}
