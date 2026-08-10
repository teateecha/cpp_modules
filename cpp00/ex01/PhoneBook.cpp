#include "PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook()
{
	std::cout << "Phonebook: Constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << firstName << ": Destructor called" << std::endl;
}

void	PhoneBook::clear_space(std::string str)
{
	for(int i = str.length() - 1, i >= 0, i--)
		if (str[i] == ' ' || str [i] == '\t')
			str.erase(i, 1);
}

void	PhoneBook::callCmd(std::string buff)
{
	
}
