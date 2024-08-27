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

void user_insert(c_list* list);

int main()
{
    bool running = true;
	bool valid = false;
    char choice = ' ';
	c_list list;

	user_insert(&list);
	list.print_list();


	while (running)
	{
		std::cout << "Do you want to continue? [Y]es, [N]o: ";
		std::cin >> choice;
		if(choice == 'N' || choice == 'n')
		{
			running = false;
		}
		else if (choice == 'Y' || choice == 'y')
		{
			clear_screen();
		}
		else
		{
			std::cout << "Invalid choice. Please enter Y or N\n";
			std::cin >> choice;
		}

		user_insert(&list);
		clear_screen();
		list.print_list();

	}
}

void user_insert(c_list* list)
{
	bool valid = false;
	char choice = ' ';
	int key = 0;
	float data = 0.0f;
	int position = 0;

	list->print_list();

	std::cout << "\nWhere do you want to insert node, [H]ead [B]ody [T]ail: ";
    std::cin >> choice;

	while (!valid)
	{
		std::cout << "\n*** INPUT ***\n";
		if (choice == 'H' || choice == 'h')
		{
			std::cout << "Enter key: ";
			std::cin >> key;
			std::cout << "Enter data: ";
			std::cin >> data;
			list->insert_head(key, data);
			valid = true;
		}
		else if (choice == 'B' || choice == 'b')
		{
			std::cout << "Enter key: ";
			std::cin >> key;
			std::cout << "Enter data: ";
			std::cin >> data;
			std::cout << "Enter position: ";
			std::cin >> position;
			list->insert_body(key, data, position);
			valid = true;
		}
		else if (choice == 'T' || choice == 't')
		{
			std::cout << "Enter key: ";
			std::cin >> key;
			std::cout << "Enter data: ";
			std::cin >> data;
			list->insert_tail(key, data);
			valid = true;
		}
		else
		{
			std::cout << "Invalid choice. Please enter H, B, or T: ";
			std::cin >> choice;
		}
		std::cout << "*** INPUT ***\n\n";

	}

}
