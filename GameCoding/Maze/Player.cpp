#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetStartPos();
	_board = board;

	//FindPathByRightHandRule();
	//FindPathByBFS();
	FindPathByAstar();
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

/**
 * 목적지의 개념이 도입된 길찾기 알고리즘
 * 입구에서부터 얼마나 떨어져 있는가
 * 출구에서부터 얼마나 떨어져 있는가
 */

// F = 최종 점수(작을수록 좋다)
// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용
// H = 목적지에서 해당 좌표까지 이동하는데 드는 비용
struct PQNode
{
	PQNode(int32 f, int32 g, Pos pos)
		: f(f), g(g), pos(pos)
	{

	}

	bool operator<(const PQNode& other) const
	{
		return f < other.f;
	}

	bool operator>(const PQNode& other) const
	{
		return f > other.f;
	}

	int32 f;	// f = g + h
	int32 g;
	Pos pos;
};
void Player::FindPathByAstar()
{
	Pos startPos = _pos;
	Pos endPos = _board->GetEndPos();

	Pos front[] =
	{
		Pos(-1, 0),		// up
		Pos(0, -1),		// left
		Pos(1, 0),		// down
		Pos(0, 1),		// right
		Pos(-1, -1),	// up_left
		Pos(1, -1),		// down_left
		Pos(1, 1),		// down_right
		Pos(-1, 1),		// up_right
	};

	int32 cost[] =
	{
		10,
		10,
		10,
		10,
		14,
		14,
		14,
		14,
	};

	const int32 size = _board->GetSize();

	// 지금까지 발견한 케이스 중 가장 좋은 비용을 저장 (작을수록 좋음)
	std::vector<std::vector<int32>> best(size, std::vector<int32>(size, INT_MAX));
	// best만으로도 판별 가능하지만 실제 방문했는지 여부를 저장 (발견과 방문은 다름)
	std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));
	// 추적
	std::vector<std::vector<Pos>> parent(size, std::vector<Pos>(size, Pos(-1, -1)));

	// BFS와 같이 queue를 이용한 예약시스템 구현
	// 하지만 더 좋은 경로 즉 최소값을 찾기 위한 방법이므로 priority_queue 사용
	// 우선순위 큐의 기본값은 std::less이므로 큰 값이 빠져나온다
	// 최소값을 찾기위해선 std::greater를 사용해야한다
	// 뒤늦게 더 좋은 경로가 발견수 있으므로 예외처리를 꼭 해야한다
	// 보통 open list는 지금까지 발견된 목록을, closed list는 실제 방문한 목록을 얘기한다
	std::priority_queue<PQNode, std::vector<PQNode>, std::greater<PQNode>> pq;

	{
		int32 g = 0;
		int32 h = 10 * (abs(endPos.y - startPos.y) + abs(endPos.x - startPos.x));

		pq.push(PQNode(g + h, g, startPos));
		best[startPos.y][startPos.x] = g + h;
		parent[startPos.y][startPos.x] = startPos;
	}

	while (!pq.empty())
	{
		// 제일 좋은 후보 찾기
		PQNode node = pq.top();
		pq.pop();

		// 동일한 좌표를 다른 경로들로 찾았을 때
		// 이미 더 빠른 경로로 인해 해당 좌표가 방문된 경우 패스
		if (visited[node.pos.y][node.pos.x])
		{
			continue;
		}
		// 이미 현재보다 더 좋은 후보가 있다면 패스 (vis없이 best만으로 가능)
		if (best[node.pos.y][node.pos.x] < node.f)
		{
			continue;
		}
		// 방문
		visited[node.pos.y][node.pos.x] = true;

		if (node.pos == endPos)
		{
			break;
		}

		for (int32 dir = 0; dir < EDir_Count * 2; dir++)
		{
			Pos next = node.pos + front[dir];
			if (!CanGo(next))
			{
				continue;
			}
			if (visited[next.y][next.x])
			{
				continue;
			}

			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(endPos.y - next.y) + abs(endPos.x - next.x));

			// 이미 현재보다 더 좋은 후보가 있다면 패스
			if (best[node.pos.y][node.pos.x] < g + h)
			{
				continue;
			}

			// 예약
			best[next.y][next.x] = g + h;
			pq.push(PQNode(g + h, g, next));
			parent[next.y][next.x] = node.pos;
		}
	}

	_path.clear();
	Pos pos = endPos;
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

	std::reverse(_path.begin(), _path.end());
}
