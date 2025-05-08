#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetStartPos();
	_board = board;

	FindPathByRightHandRule();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
	{
		return;
	}

	_sumTick += deltaTick;

	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		// move player
		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	ETileType tileType = _board->GetTileType(pos);
	return tileType == ETileType::Empty;
}

void Player::FindPathByRightHandRule()
{
	Pos pos = _pos;
	_path.clear();
	_path.push_back(pos);

	Pos endPos = _board->GetEndPos();

	Pos front[4] =
	{
		Pos(-1, 0),	// up
		Pos(0, -1),	// left
		Pos(1, 0),	// down
		Pos(0, 1),	// right
	};

	// next pos based on direction
	// Pos nextPos = pos + front[_dir];
	// rotate 90 degrees left
	// _dir = (_dir + 1) % EDir_Count;
	// rotate 90 degrees right
	// _dir = (_dir - 1) % EDir_Count;
	while (pos != endPos)
	{
		// check right side is empty
		int32 nextDir = (_dir - 1 + EDir_Count) % EDir_Count;	// prevent negative value
		if (CanGo(pos + front[nextDir]))
		{
			// rotate right
			_dir = nextDir;

			// move
			pos += front[_dir];

			// add to path
			_path.push_back(pos);
		}
		// check front side is empty
		else if (CanGo(pos + front[_dir]))
		{
			// move
			pos += front[_dir];

			// add to path
			_path.push_back(pos);
		}
		else
		{
			// rotate left
			_dir = (_dir + 1) % EDir_Count;
		}
	}
}
