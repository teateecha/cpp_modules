#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
class Contact
{
    public:
        Contact();
        ~Contact();
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
		bool		setFirstName(std::string fn);
		bool		setLastName(std::string  ln);
		bool		setNickName(std::string nn);
		bool		setPhoneNumber(std::string pn);
		bool		setDarkestSecret(std::string ds);
		void		displayDetails(void);

    private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif

