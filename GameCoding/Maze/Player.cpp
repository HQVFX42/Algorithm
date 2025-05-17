#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetStartPos();
	_board = board;

	//FindPathByRightHandRule();
	FindPathByBFS();
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

void Player::FindPathByBFS()
{
	Pos pos = _pos;
	Pos endPos = _board->GetEndPos();

	Pos front[4] =
	{
		Pos(-1, 0),	// up
		Pos(0, -1),	// left
		Pos(1, 0),	// down
		Pos(0, 1),	// right
	};

	const int32 size = _board->GetSize();
	std::vector<std::vector<bool>> discovered(size, std::vector<bool>(size, false));
	// 누구에 의해서 발견되었는지
	std::vector<std::vector<Pos>> parent(size, std::vector<Pos>(size, Pos(-1, -1)));

	std::queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;

	while (!q.empty())
	{
		pos = q.front();
		q.pop();

		if (pos == endPos)
		{
			break;
		}
		for (int32 dir = 0; dir < EDir_Count; dir++)
		{
			Pos next = pos + front[dir];
			if (CanGo(next) and !discovered[next.y][next.x])
			{
				q.push(next);
				discovered[next.y][next.x] = true;
				parent[next.y][next.x] = pos;
			}
		}
	}

	_path.clear();
	pos = endPos;
	// 시작점까지	거슬러 올라감
	while (true)
	{
		_path.push_back(pos);

		// check if pos is start point
		if (pos == parent[pos.y][pos.x])
		{
			break;
		}

		pos = parent[pos.y][pos.x];
	}

	//std::vector<Pos> temp;
	//for (int i = _path.size() - 1; i >= 0; i--)
	//{
	//	temp.push_back(_path[i]);
	//}
	//_path = temp;
	std::reverse(_path.begin(), _path.end());
}
