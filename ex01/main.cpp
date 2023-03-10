#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	get_command(std::string cmd)
{
	if (cmd == "EXIT")
		return 1;
	if (cmd == "ADD")
		return 2;
	if (cmd == "SEARCH")
		return 3;
	return 0;
}

int	main(void)
{
	PhoneBook	book;
	Contact		contacts;
	std::string	buffer = "";

	book.print_header();
	while (1)
	{
		std::cout << std::endl << "\e[0;100mENTER COMMAND :\e[0m" << std::endl;
		if (!std::getline(std::cin, buffer))
			break;
		if (get_command(buffer) == 1)
			break;
		else if (get_command(buffer) == 2)
			book.add_contact();
		else if (get_command(buffer) == 3)
		{
			if (book.nbr_contact() == 0)
				std::cout << std::endl << "\e[41mTHERE ARE NOT CONTACTS SAVED :( ENTER \"ADD\" TO REGISTER A CONTACT\e[0m" << std::endl;
			else
				book.search();
		}
	}
	return 0;
}