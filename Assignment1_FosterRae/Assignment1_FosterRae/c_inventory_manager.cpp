#include "c_inventory_manager.h"

//TODO: add input validation to all user inputs, invalid inputs are breaking the program.
/*  This fixed the first menu input validation, but the rest of the inputs are still broken.
    while (!(std::cin >> choice) || choice < 1 || choice > 8)
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid input. Please enter a number between 1 and 8: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 */
// *** Constructor ***
c_inventory_manager::c_inventory_manager()= default;

// *** Methods ***
// ** Public Methods **
void c_inventory_manager::main_menu()
{
	int choice;
	do
	{
		clear_screen();
		std::cout << "Inventory Manager" << std::endl;
		std::cout << "1. Display Inventory" << std::endl;
		std::cout << "2. Sort Inventory" << std::endl;
		std::cout << "3. Add Item" << std::endl;
		std::cout << "4. Delete Item" << std::endl;
		std::cout << "5. Edit Item" << std::endl;
		std::cout << "6. Load Inventory from File" << std::endl;
		std::cout << "7. Save Inventory to File" << std::endl;
		std::cout << "8. Exit" << std::endl;
		std::cout << "Enter your choice: ";

        while (!(std::cin >> choice) || choice < 1 || choice > 8)
        {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 8: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Switch statement to handle user choice
		switch (choice)
		{
		case 1:
			display_inventory();
			break;
		case 2:
			sort_inventory();
			break;
		case 3:
			add_item();
			break;
		case 4:
			delete_item();
			break;
		case 5:
			edit_item();
			break;
		case 6:
			load_inventory_from_file();
			break;
		case 7:
			save_inventory_to_file();
			break;
		case 8:
			break;
		default:
			handle_invalid_input();
			break;
		}
	} while (choice != 8);
}

// ** Private Methods **
void c_inventory_manager::display_inventory()
{
	clear_screen();

	// Check if the inventory is empty
	if (inventory_.is_empty())
	{
		std::cout << "Inventory is empty." << std::endl;
		return;
	}

	// Get the head node
	c_node* current_node = inventory_.get_node_from_position(0);

	// Loop through the list and print each item
	int position = 0;
    while (current_node != nullptr) {
        c_item item = current_node->get_item();
        std::cout << "Position: " << position++ << ", "
    			  << "Name: " << item.get_name() << ", "
    	          << "Type: " << item.item_type_to_string(item.get_type()) << ", "
                  << "Price: " << item.get_price() << ", "
                  << "Quantity: " << item.get_quantity() << std::endl;
        current_node = current_node->get_next();
    }

	// Wait for user input before returning to the main menu
	std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void c_inventory_manager::sort_inventory()
{
	clear_screen();

	if (inventory_.is_empty()) {
	    std::cout << "Inventory is empty." << std::endl;
	    return;
	}

	int sort_choice;
	std::cout << "Sort by:\n";
	std::cout << "1. Name\n";
	std::cout << "2. Type\n";
	std::cout << "3. Price\n";
	std::cout << "4. Quantity\n";
	std::cout << "Enter your choice: ";
	std::cin >> sort_choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// ask for ascending or descending
	int order_choice;
	std::cout << "Sort in:\n";
	std::cout << "1. Ascending\n";
	std::cout << "2. Descending\n";
	std::cout << "Enter your choice: ";
	std::cin >> order_choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Sort the inventory
	switch (sort_choice)
	{
	case 1: // Name
		if (order_choice == 1) // Ascending
		{
			inventory_.quick_sort_ascending(inventory_.get_head(), inventory_.get_tail(), 0);
		} else { 			   // Descending
			inventory_.quick_sort_descending(inventory_.get_head(), inventory_.get_tail(), 0);
		}

		break;
	case 2: // Type
		if (order_choice == 1) // Ascending
		{
			inventory_.quick_sort_ascending(inventory_.get_head(), inventory_.get_tail(), 1);
		} else { 			   // Descending
			inventory_.quick_sort_descending(inventory_.get_head(), inventory_.get_tail(), 1);
		}
		break;
	case 3: // Price
		if (order_choice == 1) // Ascending
	{
		inventory_.quick_sort_ascending(inventory_.get_head(), inventory_.get_tail(), 2);
	} else { 			   // Descending
		inventory_.quick_sort_descending(inventory_.get_head(), inventory_.get_tail(), 2);
	}
		break;
	case 4: // Quantity
		if (order_choice == 1) // Ascending
		{
			inventory_.quick_sort_ascending(inventory_.get_head(), inventory_.get_tail(), 3);
		} else { 			   // Descending
			inventory_.quick_sort_descending(inventory_.get_head(), inventory_.get_tail(), 3);
		}
		break;
	}
}

void c_inventory_manager::add_item()
{
	clear_screen();

	std::string name;
	std::cout << "Enter the name of the item: ";
	std::getline(std::cin, name);

	int type_int;
	std::cout << "Enter the type of the item (0 = WEAPON, 1 = ARMOR, 2 = POTION, 3 = CONSUMABLE, 4 = UTILITY): ";
	std::cin >> type_int;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	c_item::item_type type = static_cast<c_item::item_type>(type_int);

	float price;
	std::cout << "Enter the price of the item: ";
	std::cin >> price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int quantity;
	std::cout << "Enter the quantity of the item: ";
	std::cin >> quantity;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int key;
	std::cout << "Enter a unique key for the item: ";
	std::cin >> key;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Create the item
	c_item item(name, type, price, quantity);

	int position;
	std::cout << "Enter the position to insert the item at: \n";
	std::cout << "1. Head\n";
	std::cout << "2. Tail\n";
	std::cout << "3. Body\n";
	std::cout << "Enter your choice: ";
	std::cin >> position;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	switch (position)
	{
		case 1:
			inventory_.insert_head(key, item);
			break;
		case 2:
			inventory_.insert_tail(key, item);
			break;
		case 3:
			int body_position;
			std::cout << "Enter the position to insert the item at: ";
			std::cin >> body_position;
			inventory_.insert_body(key, item, body_position);
			break;
	}

}

void c_inventory_manager::delete_item()
{
	clear_screen();

	if (inventory_.is_empty()) {
	    std::cout << "Inventory is empty." << std::endl;
	    return;
	}

	int position;
	std::cout << "Enter the position of the item to delete: ";
	std::cin >> position;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (position == 0) 																// If the index of the item to delete is the head
	{
		inventory_.delete_head();
	}
	else if (position == inventory_.calculate_size(inventory_.get_tail() - 1)) // If the index of the item to delete is the tail
	{
		inventory_.delete_tail();
	}
	else 																		    // If the index of the item to delete is in the body
	{
		inventory_.delete_body(position);
	}
}

void c_inventory_manager::edit_item()
{
	clear_screen();

	// Check if the inventory is empty
	if (inventory_.is_empty()) {
	    std::cout << "Inventory is empty." << std::endl;
	    return;
	}

	// Get the position of the item to edit
	int position;
	std::cout << "Enter the position of the item to edit: ";
	std::cin >> position;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Get the item at the specified position
	c_node* current_node = inventory_.get_node_from_position(position);
	c_item item = current_node->get_item();

	// Edit the name of the item
	std::string name;
	std::cout << "Enter the new name of the item: ";
	std::getline(std::cin, name);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Edit the type of the item
	int type_int;
	std::cout << "Enter the new type of the item (0 = WEAPON, 1 = ARMOR, 2 = POTION, 3 = CONSUMABLE, 4 = UTILITY): ";
	std::cin >> type_int;
	c_item::item_type type = static_cast<c_item::item_type>(type_int);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Edit the price of the item
	float price;
	std::cout << "Enter the new price of the item: ";
	std::cin >> price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Edit the quantity of the item
	int quantity;
	std::cout << "Enter the new quantity of the item: ";
	std::cin >> quantity;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Update the item
	item.set_name(name);
	item.set_type(type);
	item.set_price(price);
	item.set_quantity(quantity);

	// Set the updated item in the current node
	current_node->set_item(item);
}

void c_inventory_manager::load_inventory_from_file()
{
	// TODO: Implement load_inventory_from_file
}

void c_inventory_manager::save_inventory_to_file()
{
	// TODO: Implement save_inventory_to_file
}

void c_inventory_manager::handle_invalid_input()
{
	// TODO: Implement handle_invalid_input
}

void c_inventory_manager::clear_screen()
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
