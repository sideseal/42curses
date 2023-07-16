#include <iostream>
using namespace std;
#include "Game.h"
#include "Player.h"
#include "Field.h"

Game::Game() : _player(NULL), _field(NULL)
{

}

Game::~Game()
{
	if (_player != NULL)
		delete _player;
	if (_field != NULL)
		delete _field;
}

void	Game::Init()
{
	_field = new Field();
}

void	Game::Update()
{
	if (_player == NULL)
		CreatePlayer();

	if (_player->IsDead())
	{
		delete _player;
		_player = NULL;
		CreatePlayer();
	}

	_field->Update(_player);
}

void	Game::CreatePlayer()
{
	while (_player == NULL)
	{
		cout << "--------------------" << endl;
		cout << "Create Character" << endl;
		cout << "1) Knight 2) Archer 3) Mage" << endl;
		cout << "--------------------" << endl;

		cout << "> ";

		int	input = 0;
		cin >> input;

		if (input == PT_Knight)
		{
			_player = new Knight();
		}
		else if (input == PT_Archer)
		{
			_player = new Archer();
		}
		else if (input == PT_Mage)
		{
			_player = new Mage();
		}
	}
}
