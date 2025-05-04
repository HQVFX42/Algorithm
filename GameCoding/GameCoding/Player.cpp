#include "Player.h"
#include "Map.h"
#include "Helper.h"

bool bCanMove = true;
int GPlayerX = 2;
int GPlayerY = 2;

void MovePlayer(int x, int y)
{
	if (x < 0 or x >= MAP_WIDTH or y < 0 or y >= MAP_HEIGHT)
	{
		return;
	}

	int index = y * MAP_WIDTH + x;
	if (GMap1D[index] == 1)
	{
		return;
	}

	{
		int prevIndex = GPlayerY * MAP_WIDTH + GPlayerX;
		GMap1D[prevIndex] = 0;
	}
	
	GPlayerX = x;
	GPlayerY = y;

	{
		int prevIndex = GPlayerY * MAP_WIDTH + GPlayerX;
		GMap1D[prevIndex] = 2;
	}
}

void HandleMove()
{
	// can move only when key is not pressed
	if (GMoveDir == MD_NONE)
	{
		bCanMove = true;
		return;
	}

	if (bCanMove == false)
	{
		return;
	}

	bCanMove = false;

	switch (GMoveDir)
	{
	case MD_NONE:
		break;
	case MD_LEFT:
		MovePlayer(GPlayerX - 1, GPlayerY);
		break;
	case MD_RIGHT:
		MovePlayer(GPlayerX + 1, GPlayerY);
		break;
	case MD_UP:
		MovePlayer(GPlayerX, GPlayerY - 1);
		break;
	case MD_DOWN:
		MovePlayer(GPlayerX, GPlayerY + 1);
		break;
	default:
		break;
	}
}