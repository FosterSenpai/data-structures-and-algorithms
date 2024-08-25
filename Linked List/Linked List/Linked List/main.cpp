#include "c_list.h"
#include <iostream>

int main()
{
	cList list;
	list.insert_head(1, 1.0f);
	list.insert_head(2, 2.0f);
	list.insert_head(3, 3.0f);

	list.print_list();
	return 0;
};