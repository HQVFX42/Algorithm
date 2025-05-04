#include <iostream>
#include "Helper.h"
#include "Map.h"
#include "Player.h"

int main()
{
	SetCursorOnOff(false);

	while (true)
	{
		HandleKeyInput();

		HandleMove();

		PrintMap1D();
	}
}
