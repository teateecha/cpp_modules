#include "Contact.hpp"
#include <iostream>/*for std*/
//Constructor
Contact::Contact(void)
{
	std::cout << _firstName << ": Constructor called" << std::endl;
}

//Destructor
Contact::~Contact()
{
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
	int	i = 0;
	for (size_t i = 0, i < pn.length; i++)
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

// getter
std::string	contact::getfirstname(void)
std::string	contact::getlastname(void)
std::string	contact::getnickname(void)
std::string	contact::getphonenumber(void)
std::string	contact::getdarkestsecret(void)

void	contact::displayindex(void)//todo
void	Contact::displayDetails(int idx)//TODO
