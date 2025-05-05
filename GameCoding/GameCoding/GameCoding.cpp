#include <iostream>
#include "Helper.h"
#include "Map.h"
#include "Player.h"

int main()
{
	SetCursorOnOff(false);

	while (true)
	{
		// Input
		HandleKeyInput();

		// Logic
		HandleMove();

		// Output
		PrintMap2D();
	}
}
