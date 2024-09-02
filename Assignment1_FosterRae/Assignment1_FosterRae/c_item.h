// /***********************************************************************
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// (c) 2024 Media Design School
// File Name : c_item.h
// Description : Represents an inventory item with attributes like name, type, price, and quantity.
// Author : Foster Rae
// Mail : Foster.Rae@mds.ac.nz
// ************************************************************************/

#pragma once
#include <string>
#include <utility>

class c_item
{
public:

	// Enum for item types
	enum class item_type 
	{
		WEAPON,
		ARMOR,
		POTION,
		CONSUMABLE,
		UTILITY,
	};

	// *** Constructors ***
	/**
	 * @brief default constructor
	 */
	c_item() = default;
	/**
	 * @brief constructor to create an item with the given attributes
	 * @param name - name of the item
	 * @param type - type of the item
	 * @param price - price of the item
	 * @param quantity - quantity of the item
	 *
	 *  @note This constructor uses std::move() to avoid copying the string, which is more efficient.
	 */
	c_item(std::string name, item_type type, float price, int quantity)
		: m_name_(std::move(name)), m_type_(type), m_price_(price), m_quantity_(quantity) {} // Initializer list for constructor (more efficient than writing assignments in the constructor body)

	// ** Accessors & Mutators **

	/**
	 * @brief Accessor for name
	 * @return name of the item as a string
	 */
	std::string get_name() const { return m_name_; }        // Accessor for name
	/**
	 * @brief Mutator for name
	 * @param name - string to set as the name of the item
	 */
	void set_name(const std::string& name) { m_name_ = name; } // Mutator for name

	/**
	 * @brief Accessor for type
	 *  @return type of the item as an enum 'item_type'
	 */
	item_type get_type() const { return m_type_; }        // Accessor for type
	/**
	 * @brief Mutator for type
	 * @param type - enum 'item_type' to set as the type of the item
	 *
	 *  @note Can be WEAPON, ARMOR, POTION, CONSUMABLE, or UTILITY
	 */
	void set_type(item_type type) { m_type_ = type; }     // Mutator for type

	/**
	 * @brief Accessor for price
	 * @return price of the item as a float
	 */
	float get_price() const { return m_price_; }          // Accessor for price
	/**
	 * @brief Mutator for price
	 * @param price - float to set as the price of the item
	 */
	void set_price(float price) { m_price_ = price; }     // Mutator for price

	/**
	 * @brief Accessor for quantity
	 * @return quantity of the item as an int
	 */
	int get_quantity() const { return m_quantity_; }      // Accessor for quantity
	/**
	 * @brief Mutator for quantity
	 * @param quantity - int to set as the quantity of the item
	 */
	void set_quantity(int quantity) { m_quantity_ = quantity; } // Mutator for quantity

private:
	// *** Member Variables ***
	std::string m_name_; // Name of the item
	item_type m_type_;   // Type of the item
	float m_price_;      // Price of the item
	int m_quantity_;     // Quantity of the item
};
