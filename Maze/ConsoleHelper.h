#pragma once

enum class EConsoleColor
{
	ECC_BLACK = 0,
	ECC_RED = FOREGROUND_RED,
	ECC_GREEN = FOREGROUND_GREEN,
	ECC_BLUE = FOREGROUND_BLUE,
	ECC_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
	ECC_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
	ECC_MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
	ECC_WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};

class ConsoleHelper
{
public:
	static void SetCursorPosition(int32 x, int32 y);
	static void SetCursorColor(EConsoleColor color);
	static void ShowConsoleCursor(bool bShow);
};

