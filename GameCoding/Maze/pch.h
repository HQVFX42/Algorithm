#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include <queue>
#include "Types.h"

struct Pos
{
	Pos() {}
	Pos(int32 y, int32 x) : y(y), x(x) {}

	bool operator==(const Pos& other)
	{
		return y == other.y and x == other.x;
	}

	bool operator!=(const Pos& other)
	{
		return !(*this == other);
	}

	Pos operator+(const Pos& other)
	{
		Pos result;
		result.y = y + other.y;
		result.x = x + other.x;
		return result;
	}
	Pos operator+=(const Pos& other)
	{
		y += other.y;
		x += other.x;
		return *this;
	}

	int32 y = 0;
	int32 x = 0;
};

/**
 * enum class를 사용하지 않은 이유는 EDir_Count를 int로 이용해서
 * 나머지 연산으로 이동이나 방향전환을 쉽게 하기 위한 트릭.
 */
enum EDir
{
	EDir_Up = 0,
	EDir_LEFT = 1,
	EDir_Down = 2,
	EDir_Right = 3,
	EDir_Count = 4,
};
