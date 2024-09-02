#include <iostream>

#include "c_item.h"

void test_item();
void print_item(const c_item& item);
std::string get_type_string(c_item::item_type type);

int main()
{
	test_item();
	return 0;
}

void test_item()
{
	std::cout << "Testing c_item class" << std::endl;
	std::cout << "first item variation:" << std::endl;
	c_item item("Sword", c_item::item_type::WEAPON, 10.60f, 1);
	print_item(item);

	std::cout << "\n\nsecond item variation:" << std::endl;
	item.set_name("Shield");
	item.set_type(c_item::item_type::ARMOR);
	item.set_price(5.20f);
	item.set_quantity(2);
	print_item(item);

	std::cout << "\n\nthird item variation:" << std::endl;
	item.set_name("Potion");
	item.set_type(c_item::item_type::POTION);
	item.set_price(2.24f);
	item.set_quantity(3);
	print_item(item);
}


void print_item(const c_item& item)
{
	std::cout << "Item: " << item.get_name() << std::endl;
	std::cout << "Type: " <<  get_type_string(item.get_type()) << std::endl;
	std::cout << "Price: " << item.get_price() << std::endl;
	std::cout << "Quantity: " << item.get_quantity() << std::endl;
}

std::string get_type_string(c_item::item_type type)
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
