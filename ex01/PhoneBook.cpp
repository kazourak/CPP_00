#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::print_header(void) const
{
	std::ostringstream	oss;

	oss << "\x1b[2J\x1b[1;1H";
	oss << "┌────────────────────────────────────────────┐" << std::endl;
	oss << "│  ADD    │  Save a new contact              │" << std::endl;
	oss << "│────────────────────────────────────────────│    ,==.───────." << std::endl;
	oss << "│ SEARCH  │  Display saved contacts          │   (    ) ====  \\" << std::endl;
	oss << "│         │  Each contact is displayed on a  │   ││  │ [][][] │" << std::endl;
	oss << "│         │  line.                           │ ,8││  │ [][][] │" << std::endl;
	oss << "│────────────────────────────────────────────│ 8 ││  │ [][][] │" << std::endl;
	oss << "│  EXIT   │  Quit the program                │ 8 (    ) O O O /" << std::endl;
	oss << "│         │  All saved contacts will be lost │ '88`=='───────' " << std::endl;
	oss << "└────────────────────────────────────────────┘" << std::endl;
	std::cout << oss.str();
}

void	PhoneBook::add_contact(void)
{
	static int i = 0;
	std::cout << std::endl;
	this->_contact[i % 8].init();
	this->_contact[i % 8].set_index(i % 8);
	i++;
}

void	PhoneBook::search(void)
{
	int nbr_contact = this->nbr_contact();
	int nbr_chosen = 0;
	std::string buffer = "";

	this->print_contact();
	while (1)
	{
		std::cout << "\e[44mEnter the index of the contact. Enter \"0\" to quit :\e[0m" << std::endl;
		if (!std::getline(std::cin, buffer))
			break;
		if (!buffer.empty() and buffer.length() == 1 and (buffer[0] >= '0' and buffer[0] < '9'))
			break;
	}
	nbr_chosen = buffer[0] - 48;
	if (nbr_chosen == -48 or nbr_chosen == 0)
		return ;
	if (nbr_chosen <= nbr_contact)
		this->_contact[nbr_chosen - 1].show_information();
	else
		std::cout << "\x1b[2J\x1b[1;1H" << "\e[41mTHERE ARE NOT CONTACT SAVED AT THIS INDEX :( \e[0m" << std::endl;
}

int	PhoneBook::nbr_contact(void)
{
	int	i = 0;

	while (this->_contact[i].is_empty() == 1)
		i++;
	return (i);
}

void	PhoneBook::print_contact(void)
{
	std::ostringstream oss;

	oss << "\x1b[2J\x1b[1;1H";
	oss << "┌───────────────────────────────────────────┐" << std::endl;
	oss << "│Index     │First Name│Last Name │Nickname  │" << std::endl;
	oss << "│───────────────────────────────────────────│" << std::endl;
	std::cout << oss.str();
	for(int i = 0; i < 8; i++)
	{
		this->_contact[i].print_one();
	}
	std::cout << "└───────────────────────────────────────────┘" << std::endl;
}
