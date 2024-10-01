// /***********************************************************************
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// (c) 2024 Media Design School
// File Name : c_item.h
// Description : ????????? FILL OUT ?????????
// Author : Foster Rae
// Mail : Foster.Rae@mds.ac.nz
// ************************************************************************/

#pragma once
#include <string>

class c_item
{
public:
	// *** Constructors & Destructor ***
	c_item();
	c_item(float priority, std::string identifier);
	~c_item();

	// *** Getters ***
	float get_priority() const { return m_priority_; }
	std::string get_identifier() const { return m_str_identifier_; }

	// *** Setters ***
	void set_priority(const float priority) { m_priority_ = priority; }
	void set_identifier(const std::string& identifier) { m_str_identifier_ = identifier; }

	// *** Public Functions ***
	// overload operators here
protected:
	// *** Protected Variables ***
	float m_priority_; // The priority of the item
	std::string m_str_identifier_; // The name of the item
};
