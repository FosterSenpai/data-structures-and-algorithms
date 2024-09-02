#include <iostream>

#include "c_item.h"
#include  "c_doubly_linked_list.h"

void print_item(const c_item& item);
std::string get_type_string(c_item::item_type type);

int main()
{
	std::cout << "Creating a new item..." << std::endl;
	std::string name;
	std::cout << "Enter the name of the item: ";
	std::getline(std::cin, name);
	std::cout << "Enter the type of the item (0 = WEAPON, 1 = ARMOR, 2 = POTION, 3 = CONSUMABLE, 4 = UTILITY): ";
	int type_int;
	std::cin >> type_int;
	c_item::item_type type = static_cast<c_item::item_type>(type_int);
	std::cout << "Enter the price of the item: ";
	float price;
	std::cin >> price;
	std::cout << "Enter the quantity of the item: ";
	int quantity;
	std::cin >> quantity;

	// Create the item
	c_item item(name, type, price, quantity);

	c_doubly_linked_list inventory;

	// Insert the item at the head of the list
	inventory.insert_head(0, item);

	return 0;
}



void print_item(const c_item& item)
{
	std::cout << "Item: " << item.get_name() << std::endl;
	std::cout << "Type: " <<  get_type_string(item.get_type()) << std::endl;
	std::cout << "Price: " << item.get_price() << std::endl;
	std::cout << "Quantity: " << item.get_quantity() << std::endl;
}

std::string get_type_string(const c_item::item_type type)
{
	switch (type)
	{
	case c_item::item_type::WEAPON:
		return "WEAPON";
	case c_item::item_type::ARMOR:
		return "ARMOR";
	case c_item::item_type::POTION:
		return "POTION";
	case c_item::item_type::CONSUMABLE:
		return "CONSUMABLE";
	case c_item::item_type::UTILITY:
		return "UTILITY";
	default:
		return "INVALID";
	}
}
