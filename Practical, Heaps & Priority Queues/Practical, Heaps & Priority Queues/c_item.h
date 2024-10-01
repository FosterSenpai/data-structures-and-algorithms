// /***********************************************************************
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// (c) 2024 Media Design School
// File Name : c_item.h
// Description : An item for a priority queue.
// Author : Foster Rae
// Mail : Foster.Rae@mds.ac.nz
// ************************************************************************/

#pragma once
#include <string>

/**
 * @brief Class for an item
 * \n\n
 * An item is a data structure that contains a string and a priority.
 * \n\n
 * This class provides methods to get the string and priority of the item.
 */
class c_item
{
public:
	// Constructors and Destructors
	c_item() = default;
	~c_item() = default;

	// Accessors and Mutators
	/**
	 * @brief Returns the identifier of the item.\n
	 * @return The identifier of the item as a string.
	 */
	std::string get_identifier() { return msz_identifier_; }
	/**
	 * @brief Sets the identifier of the item.\n
	 * @param identifier The identifier of the item as a string.
	 */
	void set_identifier(const std::string& identifier) { msz_identifier_ = identifier; }
	/**
	 * @brief Returns the priority of the item.\n
	 * @return The priority of the item as a float.
	 */
	float get_priority() const { return mf_priority_; }
	/**
	 * @brief Sets the priority of the item.\n
	 * @param priority The priority of the item as a float.
	 */
	void set_priority(const float priority) { mf_priority_ = priority; }

protected:
	// Member Variables
	std::string msz_identifier_; // The identifier of the item.
	float mf_priority_;          // The priority of the item.
};
