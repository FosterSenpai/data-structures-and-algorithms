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

void main_menu(c_list* list);
void user_insert(c_list* list);
void user_delete(c_list* list);

int main()
{
    bool running = true;
	bool valid = false;
    char choice = ' ';
	c_list list;

	// Start with a list of 5 nodes
	list.insert_tail(1,1.0f);
	list.insert_tail(2,2.0f);
	list.insert_tail(3,3.0f);
	list.insert_tail(4,4.0f);
	list.insert_tail(5,5.0f);


	while (running)
	{
		main_menu(&list);

		// Ask user if they want to continue
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
		clear_screen();
	}
}

void main_menu(c_list* list)
{
	bool valid = false;
	char choice = ' ';

	while (!valid)
	{
		std::cout << "What would you like to do?\n";
		std::cout << "[G]et, [I]nsert, [D]elete, [P]rint, [C]heck if key exists, [Q]uit: ";
		std::cin >> choice;

		if (choice == 'G' || choice == 'g')
		{
			list->get_node_from_key(1);
			valid = true;
		}
		else if (choice == 'I' || choice == 'i')
		{
			user_insert(list);
			valid = true;
		}
		else if (choice == 'D' || choice == 'd')
		{
			user_delete(list);
			valid = true;
		}
		else if (choice == 'P' || choice == 'p')
		{
			list->print_list();
			valid = true;
		}
		else if (choice == 'C' || choice == 'c')
		{
			int key = 0;
			std::cout << "Enter key to check: ";
			std::cin >> key;
			if (list->key_exists(key))
			{
				std::cout << "Key exists\n";
			}
			else
			{
				std::cout << "Key does not exist\n";
			}
			valid = true;
		}
		else if (choice == 'Q' || choice == 'q')
		{
			valid = true;
		}
		else
		{
			std::cout << "Invalid choice. Please enter G, I, D, P, C, or Q\n";
			std::cin >> choice;
		}
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

void user_delete(c_list* list)
{
	bool valid = false;
	char choice = ' ';
	int position = 0;

	list->print_list();

	std::cout << "\nWhere do you want to delete node, [H]ead [B]ody [T]ail: ";
	std::cin >> choice;

	while (!valid)
	{
		std::cout << "\n*** INPUT ***\n";
		if (choice == 'H' || choice == 'h')
		{
			list->delete_head();
			valid = true;
		}
		else if (choice == 'B' || choice == 'b')
		{
			std::cout << "Enter position: ";
			std::cin >> position;
			list->delete_body(position);
			valid = true;
		}
		else if (choice == 'T' || choice == 't')
		{
			list->delete_tail();
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
