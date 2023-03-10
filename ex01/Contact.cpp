#include "Contact.hpp"
#include <iomanip>
#include <sstream>

Contact::Contact()
{

}

Contact::~Contact()
{

}

std::string Contact::get_intput(std::string msg)
{
	std::string buffer = "";
	while (1)
	{
		std::cout << msg << std::endl;
		if (!std::getline(std::cin, buffer))
			break;
		if (!buffer.empty() and buffer[0] != '\0')
			break;
	}
	return (buffer);
}

void Contact::init(void)
{
	this->_first_name = this->get_intput("\e[44mEnter the first name :\e[0m");
	this->_last_name = this->get_intput("\e[44mEnter the last name :\e[0m");
	this->_nickname = this->get_intput("\e[44mEnter the nickname :\e[0m");
	this->_phone_number = this->get_intput("\e[44mEnter the phone number :\e[0m");
	this->_darkest_secret = this->get_intput("\e[44mEnter the darkest secret :\e[0m");
}

void Contact::set_index(int index)
{
	this->_index = index + 1;
}

std::string Contact::get_resized(std::string string, int max_len)
{
	std::string new_str = string;
	if (new_str.length() > (unsigned long)max_len)
	{
		new_str[9] = '.';
		new_str.resize(max_len);
	}
	return new_str;
}

void	Contact::show_information(void)
{
	std::ostringstream oss;

	oss << "\x1b[2J\x1b[1;1H";
	oss << "\e[1;37mFirst Name :\e[0m " << this->_first_name << std::endl;
	oss << "\e[1;37mLast Name :\e[0m " << this->_last_name << std::endl;
	oss << "\e[1;37mNickname :\e[0m " << this->_nickname << std::endl;
	oss << "\e[1;37mPhone :\e[0m " << this->_phone_number << std::endl;
	oss << "\e[1;37mSecret :\e[0m " << this->_darkest_secret << std::endl;
	std::cout << oss.str() << std::endl;
}

void Contact::print_one(void)
{
	std::ostringstream oss;

	if (this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty() || this->_phone_number.empty() || this->_darkest_secret.empty())
		return;
	oss << "│" << std::setw(10) << std::setfill(' ') << this->_index << "│";
	oss << std::setw(10) << std::setfill(' ') << this->get_resized(this->_first_name, 10) << "│";
	oss << std::setw(10) << std::setfill(' ') << this->get_resized(this->_last_name, 10) << "│";
	oss << std::setw(10) << std::setfill(' ') << this->get_resized(this->_phone_number, 10) << "│";
	std::cout << oss.str() << std::endl;
}

int	Contact::is_empty(void)
{
	if (this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty() || this->_phone_number.empty() || this->_darkest_secret.empty())
		return 0;
	return 1;
}