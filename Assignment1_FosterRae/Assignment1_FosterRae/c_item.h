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
	c_item(std::string name, const item_type type, const float price, const int quantity)
		: m_name_(std::move(name)), m_type_(type), m_price_(price), m_quantity_(quantity) {} // Initializer list for constructor (more efficient than writing assignments in the constructor body)

	// ** Accessors & Mutators **

	/**
	 * @brief Accessor for name
	 * @return name of the item as a string
	 */
	std::string get_name() const { return m_name_; }        		// Accessor for name
	/**
	 * @brief Mutator for name
	 * @param name - string to set as the name of the item
	 */
	void set_name(const std::string& name) { m_name_ = name; } 		// Mutator for name

	/**
	 * @brief Accessor for type
	 *  @return type of the item as an enum 'item_type'
	 */
	item_type get_type() const { return m_type_; }        			// Accessor for type
	/**
	 * @brief Mutator for type
	 * @param type - enum 'item_type' to set as the type of the item
	 *
	 *  @note Can be WEAPON, ARMOR, POTION, CONSUMABLE, or UTILITY
	 */
	void set_type(const item_type type) { m_type_ = type; }     	// Mutator for type

	/**
	 * @brief Accessor for price
	 * @return price of the item as a float
	 */
	float get_price() const { return m_price_; }          			// Accessor for price
	/**
	 * @brief Mutator for price
	 * @param price - float to set as the price of the item
	 */
	void set_price(const float price) { m_price_ = price; }     	// Mutator for price

	/**
	 * @brief Accessor for quantity
	 * @return quantity of the item as an int
	 */
	int get_quantity() const { return m_quantity_; }      			  // Accessor for quantity
	/**
	 * @brief Mutator for quantity
	 * @param quantity - int to set as the quantity of the item
	 */
	void set_quantity(const int quantity) { m_quantity_ = quantity; } // Mutator for quantity

	// *** Comparison operators ***
	/** 
	 * @brief Overloaded comparison operator for sorting items
	 * @param other - the item to compare to
	 * @return true if the item is less than the other item
	 */
	bool operator<(const c_item& other) const;
	/**
	 * @brief Overloaded comparison operator for sorting items
	 * @param other - the item to compare to
	 * @return true if the item is greater than the other item
	 */
	bool operator>(const c_item& other) const;

	// *** Comparison Functions ***
	bool compare_by_name(const c_item& other) const { return m_name_ < other.m_name_; } 			// Compare by name
	bool compare_by_type(const c_item& other) const { return m_type_ < other.m_type_; } 			// Compare by type
	bool compare_by_price(const c_item& other) const { return m_price_ < other.m_price_; } 			// Compare by price
	bool compare_by_quantity(const c_item& other) const { return m_quantity_ < other.m_quantity_; } // Compare by quantity

	inline std::string item_type_to_string(item_type type) const
	{
		switch (type)
		{
		case item_type::WEAPON:
			return "WEAPON";
		case item_type::ARMOR:
			return "ARMOR";
		case item_type::POTION:
			return "POTION";
		case item_type::CONSUMABLE:
			return "CONSUMABLE";
		case item_type::UTILITY:
			return "UTILITY";
		default:
			return "INVALID";
		}
	}

private:

	// *** Member Variables ***

	std::string m_name_; // Name of the item
	item_type m_type_;   // Type of the item
	float m_price_;      // Price of the item
	int m_quantity_;     // Quantity of the item

};

inline bool c_item::operator<(const c_item& other) const
{
    constexpr float epsilon = 0.0001f; // Epsilon value for float comparison

    if (m_name_ != other.m_name_) {
        return m_name_ < other.m_name_; 												// Compare strings alphabetically
    } else if (item_type_to_string(m_type_) != item_type_to_string(other.m_type_)) {
        return item_type_to_string(m_type_) < item_type_to_string(other.m_type_); 		// Compare enum strings alphabetically
    } else if (m_price_ - other.m_price_ < -epsilon) {
        return m_price_ < other.m_price_; 												// Compare floats numerically
    } else {
        return m_quantity_ < other.m_quantity_; 										// Compare integers numerically
    }
}

inline bool c_item::operator>(const c_item& other) const
{
    constexpr float epsilon = 0.0001f; // Epsilon value for float comparison

    if (m_name_ != other.m_name_) {
        return m_name_ > other.m_name_; 												// Compare strings alphabetically
    } else if (item_type_to_string(m_type_) != item_type_to_string(other.m_type_)) {
        return item_type_to_string(m_type_) > item_type_to_string(other.m_type_); 		// Compare enum strings alphabetically
    } else if (m_price_ - other.m_price_ > epsilon) {
        return m_price_ > other.m_price_; 												// Compare floats numerically
    } else {
        return m_quantity_ > other.m_quantity_; 										// Compare integers numerically
    }
}


