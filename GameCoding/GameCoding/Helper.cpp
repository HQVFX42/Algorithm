#include "Helper.h"
#include <Windows.h>

MoveDir GMoveDir;

void HandleKeyInput()
{
	if (::GetAsyncKeyState(VK_LEFT))
	{
		GMoveDir = MD_LEFT;
	}
	else if (::GetAsyncKeyState(VK_RIGHT))
	{
		GMoveDir = MD_RIGHT;
	}
	else if (::GetAsyncKeyState(VK_UP))
	{
		GMoveDir = MD_UP;
	}
	else if (::GetAsyncKeyState(VK_DOWN))
	{
		GMoveDir = MD_DOWN;
	}
	else
	{
		GMoveDir = MD_NONE;
	}
}

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { (SHORT)x, (SHORT)y };
	::SetConsoleCursorPosition(output, pos);
}

void SetCursorOnOff(bool visibile)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	::GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = visibile;
	::SetConsoleCursorInfo(output, &cursorInfo);
}