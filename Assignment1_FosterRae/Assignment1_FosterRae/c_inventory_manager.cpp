#include "c_inventory_manager.h"

// *** Constructor ***
c_inventory_manager::c_inventory_manager()= default;

// *** Methods ***
// ** Public Methods **
void c_inventory_manager::main_menu()
{
	int choice;
	std::string load_file_path;

	do
	{
		system("cls");
		std::cout << "Inventory Manager - Foster Rae\n\n";
		std::cout << "1. Display Inventory\n";
		std::cout << "2. Sort Inventory\n";
		std::cout << "3. Add Item\n";
		std::cout << "4. Delete Item\n";
		std::cout << "5. Edit Item\n";
		std::cout << "6. Load Inventory from File (NOT WORKING)\n";
		std::cout << "7. Save Inventory to File(NOT WORKING)\n";
		std::cout << "8. Exit\n\n";
		std::cout << "Enter your choice: ";

		// Input validation
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
			system("cls");
			display_inventory();
			// Wait for user input before returning to the main menu
			std::cout << "\nPress Enter to continue...";
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		case 2:
			sort_inventory();
			system("cls");
			std::cout << "Inventory sorted.\n";
			display_inventory();
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
			std::cout << "Load Inventory from File function is yet to be implemented.\n";
            break;
		case 7:
			std::cout << "Save Inventory to File function is yet to be implemented.\n";
			break;
		case 8:
			break;
		}
	} while (choice != 8);
}

// ** Private Methods **
void c_inventory_manager::display_inventory()
{

	// Check if the inventory is empty
	if (inventory_.is_empty())
	{
		std::cout << "============================== Inventory ==============================\n";
		std::cout << "Inventory is empty.\n";
		std::cout << "=======================================================================\n";

		// Wait for user input before returning to the main menu
		return;
	}

	// Get the head node
	c_node* current_node = inventory_.get_node_from_position(0);

	// Loop through the list and print each item
	int position = 0;
	//decorate the output
	std::cout << "============================== Inventory ==============================\n";
    while (current_node != nullptr) {
        c_item item = current_node->get_item();
        std::cout << "Position: " << position++ << ", "
    			  << "Name: " << item.get_name() << ", "
    	          << "Type: " << item.item_type_to_string(item.get_type()) << ", "
                  << "Price: " << item.get_price() << ", "
                  << "Quantity: " << item.get_quantity() << '\n';
        current_node = current_node->get_next();
    }
	std::cout << "=======================================================================\n";
}

void c_inventory_manager::sort_inventory()
{
	system("cls");

	// Check if the inventory is empty
	if (inventory_.is_empty())
	{
		std::cout << "============================== Inventory ==============================\n";
		std::cout << "Inventory is empty.\n";
		std::cout << "=======================================================================\n";

		// Wait for user input before returning to the main menu
		std::cout << "\nPress Enter to continue...";
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}

	int sort_choice;
	std::cout << "Sort by:\n";
	std::cout << "1. Name\n";
	std::cout << "2. Type\n";
	std::cout << "3. Price\n";
	std::cout << "4. Quantity\n";
	std::cout << "\nEnter your choice: ";
	std::cin >> sort_choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// ask for ascending or descending
	int order_choice;
	std::cout << "\n\nSort in:\n";
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
	system("cls");

	std::string name;
	std::cout << "Enter the name of the item: ";
	std::getline(std::cin, name);

	int type_int;
	std::cout << "Enter the type of the item (0 = ARMOR, 1 = CONSUMABLE, 2 = POTION, 3 = UTILITY, 4 = WEAPON): ";
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
	std::cout << "\nEnter the position to insert the item at: \n";
	std::cout << "1. Head\n";
	std::cout << "2. Tail\n";
	std::cout << "3. Body\n";
	std::cout << "\nEnter your choice: ";
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
	system("cls");

	// Check if the inventory is empty
	if (inventory_.is_empty())
	{
		std::cout << "============================== Inventory ==============================\n";
		std::cout << "Inventory is empty.\n";
		std::cout << "=======================================================================\n";

		// Wait for user input before returning to the main menu
		std::cout << "\nPress Enter to continue...";
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}

	display_inventory();

	int position;
	std::cout << "\nEnter the position of the item to delete: ";
	std::cin >> position;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Confirm deletion
	char choice;
	std::cout << "\nAre you sure you want to delete the item at position " << position << "? (y/n): ";
	std::cin >> choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (choice != 'y' && choice != 'Y')
	{
		return;
	}

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
	system("cls");

	// Check if the inventory is empty
	if (inventory_.is_empty())
	{
		std::cout << "============================== Inventory ==============================\n";
		std::cout << "Inventory is empty.\n";
		std::cout << "=======================================================================\n";

		// Wait for user input before returning to the main menu
		std::cout << "\nPress Enter to continue...";
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}

	display_inventory();

	// Get the position of the item to edit
	int position;
	std::cout << "\nEnter the position of the item to edit: ";
	std::cin >> position;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Confirm edit
	char choice;
	std::cout << "\nAre you sure you want to edit the item at position " << position << "? (y/n): ";
	std::cin >> choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (choice != 'y' && choice != 'Y')
	{
		return;
	}

	system("cls");
	display_inventory();
	std::cout << "\nEditing position " << position << '\n';

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
	std::cout << "Enter the new type of the item (0 = ARMOR, 1 = CONSUMABLE, 2 = POTION, 3 = UTILITY, 4 = WEAPON): ";
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

void c_inventory_manager::replace_backslashes(std::string& file_path)
{
	for (char& ch : file_path) 
	{
		if (ch == '\\')
		{
			ch = '/';
		}
	}
}

void c_inventory_manager::load_inventory_from_file(const std::string& file_path)
{
	// Check if the file exists
    std::ifstream file(file_path);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << file_path << '\n';
        return;
    }

    std::string line;
    // Skip the header line
    std::getline(file, line);
	// Read each line of the file
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string name, type_str, price_str, quantity_str;

        if (std::getline(iss, name, '/') &&
            std::getline(iss, type_str, '/') &&
            std::getline(iss, price_str, '/') &&
            std::getline(iss, quantity_str, '/'))
        {
            // Remove leading and trailing whitespaces
            name = trim(name);
            type_str = trim(type_str);
            price_str = trim(price_str);
            quantity_str = trim(quantity_str);

            // Convert strings to appropriate types
            c_item::item_type type = string_to_item_type(type_str);
            float price = std::stof(price_str);
            int quantity = std::stoi(quantity_str);

            // Create c_item object
            c_item item(name, type, price, quantity);

            // Insert item into inventory
            int key = generate_unique_key();
            inventory_.insert_tail(key, item);
        }
    }

    file.close();
}


void c_inventory_manager::save_inventory_to_file()
{
	// To be implemented
}

c_item::item_type c_inventory_manager::string_to_item_type(const std::string& type)
{
	if (type == "ARMOR") return c_item::item_type::ARMOR;
    if (type == "CONSUMABLE") return c_item::item_type::CONSUMABLE;
    if (type == "POTION") return c_item::item_type::POTION;
    if (type == "UTILITY") return c_item::item_type::UTILITY;
    if (type == "WEAPON") return c_item::item_type::WEAPON;
    throw std::invalid_argument("Invalid item type: " + type);
}

std::string c_inventory_manager::trim(const std::string& str)
{
	// Trim leading spaces
	size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
    {
        return str;
	}

	// Trim trailing spaces
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

int c_inventory_manager::generate_unique_key()
{
	static int key = 0;
    return ++key;
}
