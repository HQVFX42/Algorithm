#pragma once

#include "CaVector.h"

class Board;

class Player
{
	enum
	{
		MOVE_TICK = 250,
	};
public:

	void Init(Board* board);
	void Update(uint64 deltaTick);

	void SetPos(Pos pos) { _pos = pos; }
	Pos GetPos() { return _pos; }

	bool CanGo(Pos pos);

private:
	void FindPathByRightHandRule();
	void FindPathByBFS();
	void FindPathByAstar();

private:
	Pos _pos;
	int32 _dir = EDir_Up;
	Board* _board = nullptr;

	//CaVector<Pos> _path;
	std::vector<Pos> _path;
	int32 _pathIndex = 0;
	uint64 _sumTick = 0;
};

