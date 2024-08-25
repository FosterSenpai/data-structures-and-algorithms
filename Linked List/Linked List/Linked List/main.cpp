#include "c_list.h"
#include <iostream>

int main()
{
	// Testing the linked list.
	// ********** Inserting nodes **********

	// Head insertion.
	cList head_insert_list;
	head_insert_list.insert_head(59, 98.2f);
	head_insert_list.print_list();
	head_insert_list.insert_head(60, 98.3f);
	head_insert_list.print_list();
	head_insert_list.insert_head(41, 6.2f);
	head_insert_list.print_list();
	head_insert_list.insert_head(45, 6.8f);
	head_insert_list.print_list();
	head_insert_list.insert_head(47, 6.9f);
	head_insert_list.print_list();

	// Tail insertion.
	std::cout << "============================= Tail insertion =============================" << std::endl;
	cList tail_insert_list;
	tail_insert_list.insert_tail(59, 98.2f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(60, 98.3f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(41, 6.2f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(45, 6.8f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(47, 6.9f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(50, 7.5f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(55, 8.1f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(57, 8.3f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(62, 9.2f);
	tail_insert_list.print_list();
	tail_insert_list.insert_tail(65, 9.5f);
	tail_insert_list.print_list();

	// Body insertion.
	std::cout << "============================= Body insertion =============================" << std::endl;
	cList body_insert_list;
	body_insert_list.insert_body(0, 59, 98.2f);
	body_insert_list.print_list();
	std::cout << "\n*** Inserting 60, 98.3f at position 1 ***" << std::endl;
	body_insert_list.insert_body(1, 60, 98.3f);
	body_insert_list.print_list();
	std::cout << "\n*** Inserting 41, 6.2f at position 1 ***" << std::endl;
	body_insert_list.insert_body(1, 41, 6.2f);
	body_insert_list.print_list();
	std::cout << "\n*** Inserting 45, 6.8f at position 2 ***" << std::endl;
	body_insert_list.insert_body(2, 45, 6.8f);
	body_insert_list.print_list();
	std::cout << "\n*** Inserting 47, 6.9f at position 3 ***" << std::endl;
	body_insert_list.insert_body(3, 47, 6.9f);
	body_insert_list.print_list();
	std::cout << "\n*** Inserting 50, 7.5f at position 3 ***" << std::endl;
	body_insert_list.insert_body(3, 50, 7.5f);
	body_insert_list.print_list();
	std::cout << "\n*** Inserting 55, 8.1f at position 4 ***" << std::endl;
	body_insert_list.insert_body(4, 55, 8.1f);
	body_insert_list.print_list();

	// ********** Deleting nodes **********

	// Head deletion.
	std::cout << "============================= Head deletion =============================" << std::endl;
	std::cout << "Before deleting head" << std::endl;
	body_insert_list.print_list();
	std::cout << "\n*** Deleting head ***" << std::endl;
	head_insert_list.delete_head();
	head_insert_list.print_list();


	return 0;
};