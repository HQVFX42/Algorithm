#pragma once

enum class EConsoleColor
{
	Black = 0,
	Red = FOREGROUND_RED,
	Green = FOREGROUND_GREEN,
	Blue = FOREGROUND_BLUE,
	Yellow = FOREGROUND_RED | FOREGROUND_GREEN,
	Cyan = FOREGROUND_GREEN | FOREGROUND_BLUE,
	Magenta = FOREGROUND_RED | FOREGROUND_BLUE,
	White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};

class ConsoleHelper
{
public:
	static void SetCursorPosition(int32 x, int32 y);
	static void SetCursorColor(EConsoleColor color);
	static void ShowConsoleCursor(bool bShow);
};

