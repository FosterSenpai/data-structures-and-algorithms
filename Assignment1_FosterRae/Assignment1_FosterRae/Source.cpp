#include <iostream>
#include "c_inventory_manager.h"

// temporary print inventory method
void print_inventory(c_doubly_linked_list& inventory)
{
	// Get the head node
	c_node* current_node = inventory.get_node_from_position(0);

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
int main()
{
	//// Create an instance of the inventory manager
	//c_inventory_manager inventory_manager;
	//// Call the main menu method, which drives the program
	//inventory_manager.main_menu();

	// Create an instance list for testing quicksort
	c_doubly_linked_list list;
	// Add some items to the list
    c_item* item1 = new c_item("aswfsa", c_item::item_type::WEAPON, 14.2f, 14);
    list.insert_head(1, *item1);
	c_item* item2 = new c_item("asfas", c_item::item_type::WEAPON, 234.3f, 11);
	list.insert_head(2, *item2);
	c_item* item3 = new c_item("bdss", c_item::item_type::ARMOR, 32.7f, 65);
	list.insert_head(3, *item3);
	c_item* item4 = new c_item("afs", c_item::item_type::WEAPON, 43.3f, 1);
	list.insert_head(4, *item4);
	c_item* item5 = new c_item("sgew", c_item::item_type::UTILITY, 46.3f, 5);
	list.insert_head(5, *item5);
	c_item* item6 = new c_item("hgsret", c_item::item_type::ARMOR, 64.2f, 1);
	list.insert_head(6, *item6);
	c_item* item7 = new c_item("rhadd", c_item::item_type::CONSUMABLE, 52.2f, 7);
	list.insert_head(7, *item7);
	c_item* item8 = new c_item("nrdsf", c_item::item_type::WEAPON, 34.2f, 23);
	list.insert_head(8, *item8);
	c_item* item9 = new c_item("vdsg", c_item::item_type::POTION, 37.8f, 22);
	list.insert_head(9, *item9);
	c_item* item10 = new c_item("zdshwrn", c_item::item_type::UTILITY, 10.6f, 18);


	// Display the list before sorting
	std::cout << "============================= Quicksort tests =============================" << '\n';
	std::cout << "Before sorting:" << '\n';
	print_inventory(list);

	std::cout << "\n++++++++++++ NAME SORTS ++++++++++++" << '\n';

	std::cout << "\n";
	std::cout << "Sort by name ascending:" << '\n';
	list.quick_sort_ascending(list.get_head(), list.get_tail(), 0);
	print_inventory(list);

	std::cout << "\n";
	std::cout << "Sort by name descending:" << '\n';
	list.quick_sort_descending(list.get_head(), list.get_tail(), 0);
	print_inventory(list);

	std::cout << "\n++++++++++++ TYPE SORTS ++++++++++++" << '\n';

	std::cout << "\n";
	std::cout << "Sort by type ascending:" << '\n';
	list.quick_sort_ascending(list.get_head(), list.get_tail(), 1);
	print_inventory(list);

	std::cout << "\n";
	std::cout << "Sort by type descending:" << '\n';
	list.quick_sort_descending(list.get_head(), list.get_tail(), 1);
	print_inventory(list);

	std::cout << "\n++++++++++++ PRICE SORTS ++++++++++++" << '\n';

	std::cout << "\n";
	std::cout << "sort by price ascending:" << '\n';
	list.quick_sort_ascending(list.get_head(), list.get_tail(), 2);
	print_inventory(list);

	std::cout << "\n";
	std::cout << "Sort by price descending:" << '\n';
	list.quick_sort_descending(list.get_head(), list.get_tail(), 2);
	print_inventory(list);

	std::cout << "\n++++++++++++ QUANTITY SORTS ++++++++++++" << '\n';

	std::cout << "\n";
	std::cout << "Sort by quantity ascending:" << '\n';
	list.quick_sort_ascending(list.get_head(), list.get_tail(), 3);
	print_inventory(list);

	std::cout << "\n";
	std::cout << "Sort by quantity descending:" << '\n';
	list.quick_sort_descending(list.get_head(), list.get_tail(), 3);
	print_inventory(list);
	return 0;
}
