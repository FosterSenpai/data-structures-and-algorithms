#include "c_list.h"
#include <iostream>
#include <windows.h>

void clear_screen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = { 0, 0 };

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ', cellCount, homeCoords, &count)) return;
    if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count)) return;

    SetConsoleCursorPosition(hConsole, homeCoords);
}

void test_insert_head(cList& head_insert_list);
void test_insert_tail(cList& tail_insert_list);
void test_insert_body(cList& body_insert_list);

void test_delete_head(cList& head_delete_list);
void test_delete_tail(cList& tail_delete_list);
void test_delete_body(cList& body_delete_list);

int main()
{
	bool on = true;
	int key = 0;
	float value = 0.0f;
	cList list;

	// Test data
	list.insert_head(59, 98.2f);
	list.insert_head(60, 98.3f);
	list.insert_head(41, 6.2f);
	list.insert_head(45, 6.8f);
	list.insert_head(47, 6.9f);
	list.insert_tail(54, 9.0f);
	list.insert_tail(55, 9.1f);
	list.insert_tail(56, 9.2f);
	list.insert_tail(57, 9.3f);
	list.insert_tail(58, 9.4f);
	list.print_list();

	// Input and delete loop
	while (on == true)
	{
		std::cout << "[I]nput or [D]elete" << '\n';
		char choice;
		std::cin >> choice;
		if (choice == 'D' || choice == 'd')
		{
			std::cout << "Select a position to delete from [H]ead [B]ody [T]ail" << '\n';
			char position;
			std::cin >> position;

			if (position == 'H' || position == 'h')
			{
				list.delete_head();
				list.print_list();
			}
			else if (position == 'T' || position == 't')
			{
				list.delete_tail();
				list.print_list();
			}
			else if (position == 'B' || position == 'b')
			{
				int body_position = 0;
				std::cout << "Enter the position to delete the node: ";
				std::cin >> body_position;
				list.delete_body(body_position);
				list.print_list();
			}
			else
			{
				std::cout << "Invalid position" << '\n';
			}
		}
		else if (choice == 'I' || choice == 'i')
		{
			std::cout << "Enter The key and value to insert in the list" << '\n';
			std::cout << "Key: ";
			std::cin >> key;
			std::cout << "Value: ";
			std::cin >> value;
			std::cout << "Select a position to insert into [H]ead [B]ody [T]ail" << '\n';
			char position;
			std::cin >> position;

			if (position == 'H' || position == 'h')
			{
				list.insert_head(key, value);
				list.print_list();
			}
			else if (position == 'T' || position == 't')
			{
				list.insert_tail(key, value);
				list.print_list();
			}
			else if (position == 'B' || position == 'b')
			{
				int body_position = 0;
				std::cout << "Enter the position to insert the node: ";
				std::cin >> body_position;
				list.insert_body(body_position, key, value);
				list.print_list();
			}
			else
			{
				std::cout << "Invalid position" << '\n';
			}

			std::cout << "Do you want to continue? [Y]es [N]o" << '\n';
			std::cin >> choice;
			if (choice == 'N' || choice == 'n')
			{
				on = false;
			}
			else if (choice == 'Y' || choice == 'y')
			{
				on = true;
			}
			else
			{
				std::cout << "Invalid choice, Continuing" << '\n';
			}
		}

		//clear the screen
		clear_screen();
		list.print_list();
		std::cout <<"\n\n";
	}


	return 0;
};


void test_insert_head(cList& head_insert_list)
{
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << '\n';
	std::cout << "============ Head insertion ============" << '\n';
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << '\n';
	head_insert_list.insert_head(59, 98.2f);
	head_insert_list.print_list();
	head_insert_list.insert_head(60, 98.3f);
	head_insert_list.print_list();
	head_insert_list.insert_head(41, 6.2f);
	head_insert_list.print_list();
	head_insert_list.insert_head(45, 6.8f);
	head_insert_list.print_list();
	head_insert_list.insert_head(47, 6.9f);
	head_insert_list.print_list();
}

void test_insert_tail(cList& tail_insert_list)
{
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << '\n';
	std::cout << "============ Tail insertion ============" << '\n';
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << '\n';
	tail_insert_list.insert_tail(59, 98.2f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(60, 98.3f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(41, 6.2f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(45, 6.8f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(47, 6.9f);
	tail_insert_list.print_list();
}

void test_insert_body(cList& body_insert_list)
{
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << '\n';
	std::cout << "============ Body insertion ============" << '\n';
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << '\n';
	body_insert_list.insert_body(59, 91, 0);
	body_insert_list.print_list();
	body_insert_list.insert_body(60, 92, 1);
	body_insert_list.print_list();
	body_insert_list.insert_body(41, 6, 2);
	body_insert_list.print_list();
	body_insert_list.insert_body(45, 8, 3);
	body_insert_list.print_list();
	body_insert_list.insert_body(47, 9, 4);
	body_insert_list.print_list();
	body_insert_list.insert_body(47, 90, 5);
	body_insert_list.print_list();
	body_insert_list.insert_body(47, 66, 6);
	body_insert_list.print_list();
}

void test_delete_head(cList& head_delete_list)
{
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << '\n';
	std::cout << "============ Head deletion ============" << '\n';
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << '\n';
	std::cout << "****** Before deletion ******" << '\n';
	head_delete_list.print_list();
	std::cout << "\n\n****** First deletion ******" << '\n';
	head_delete_list.delete_head();
	head_delete_list.print_list();
	std::cout << "\n\n****** Second deletion ******" << '\n';
	head_delete_list.delete_head();
	head_delete_list.print_list();
	std::cout << "\n\n****** Third deletion ******" << '\n';
	head_delete_list.delete_head();
	head_delete_list.print_list();
	std::cout << "\n\n****** Fourth deletion ******" << '\n';
	head_delete_list.delete_head();
	head_delete_list.print_list();
	std::cout << "\n\n****** Fifth deletion ******" << '\n';
	head_delete_list.delete_head();
	head_delete_list.print_list();
}
