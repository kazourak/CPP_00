#ifndef CPP00_PHONEBOOK_H
#define CPP00_PHONEBOOK_H
# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void	search(void);
	int		nbr_contact(void);
	void	add_contact(void);
	void	print_contact(void);
	void	print_header(void) const;

private:
	Contact	_contact[8];
};

#endif //CPP00_PHONEBOOK_H
