#include "Contact.hpp"
#include <iostream>/*for std*/
//Constructor
Contact::Contact(void)
{
	std::cout << "Contact: Constructor called" << std::endl;
}

//Destructor
Contact::~Contact()
{
	if (_firstName.empty())
		std::cout << "Contact: Destructor called" << std::endl;
	else
		std::cout << _firstName << ": Destructor called" << std::endl;
}

// Setter
bool	Contact::setFirstName(std::string fn)
{
	if (fn.empty())
		return (false);
	this->_firstName = fn;
	return (true);
}

bool	Contact::setLastName(std::string  ln)
{
	if (ln.empty())
		return (false);
	this->_lastName = ln;
	return (true);
}

bool	Contact::setNickName(std::string nn)
{
	if (nn.empty())
		return (false);
	this->_nickname = nn;
	return (true);
}

bool	Contact::setPhoneNumber(std::string pn)
{
	if (pn.empty())
		return (false);
	for (size_t i = 0; i < pn.length(); i++)
	{
		if (i == 0 && pn[i] == '+')
			i++ ;
		else if (!isdigit(pn[i]))
			return (false);
	}
	this->_phoneNumber = pn;
	return (true);
}

bool	Contact::setDarkestSecret(std::string ds)
{
	if (ds.empty())
		return (false);
	this->_darkestSecret = ds;
	return (true);
}

//setter
std::string	Contact::getFirstName(void)
{
	return(this->_firstName);
}

std::string	Contact::getLastName(void)
{
	return(this->_lastName);
}

std::string	Contact::getNickName(void)
{
	return(this->_nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return(this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void)
{
	return(this->_darkestSecret);
}

void	Contact::displayDetails(void)
{
	std::cout << "first name: " << _firstName << std::endl;
	std::cout << "last name: " << _lastName << std::endl;
	std::cout << "nickname: " << _nickname << std::endl;
	std::cout << "phone number: " << _phoneNumber << std::endl;
	std::cout << "darkest secret: " << _darkestSecret << std::endl;
}
