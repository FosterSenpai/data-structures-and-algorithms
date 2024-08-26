#include "c_list.h"
#include <iostream>
#include <windows.h>

void clear_screen()
{
    HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (h_console == INVALID_HANDLE_VALUE) return;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cell_count;
    COORD homeCoords = { 0, 0 };

    if (!GetConsoleScreenBufferInfo(h_console, &csbi)) return;
    cell_count = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(h_console, (TCHAR)' ', cell_count, homeCoords, &count)) return;
    if (!FillConsoleOutputAttribute(h_console, csbi.wAttributes, cell_count, homeCoords, &count)) return;

    SetConsoleCursorPosition(h_console, homeCoords);
}

int main()
{
	return 0;
}