#ifndef CPP00_CONTACT_H
#define CPP00_CONTACT_H
# include <string>
# include <iostream>

class Contact
{
public:
	Contact(void);
	~Contact(void);
	void		init(void);
	void		print_one(void);
	int			is_empty(void);
	void		set_index(int index);
	void		show_information(void);
	std::string	get_intput(std::string msg);
	std::string	get_resized(std::string string, int max_len);

private:
	int			_index;
	std::string _nickname;
	std::string _last_name;
	std::string _first_name;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif //CPP00_CONTACT_H
