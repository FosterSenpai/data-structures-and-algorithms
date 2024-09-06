#include <iostream>
#include "c_inventory_manager.h"

int main()
{
	// Create an instance of the inventory manager
	c_inventory_manager inventory_manager;
	// Call the main menu method, which drives the program
	inventory_manager.main_menu();
	return 0;
}
