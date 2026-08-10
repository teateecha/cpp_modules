#include "Contact.hpp"
#include <iostream>/*for std*/

Contact::Contact(void)
{
	std::cout << _firstName << ": Constructor called" << std::endl;
}

Contact::~Contact()
{
    std::cout << _firstName << ": Destructor called" << std::endl;
}

void	setContact(std::string fn,
			std::string ln,
			std::string nn,
			std::string pn,
			std::string ds)
{
	std::cin>>buff
}
