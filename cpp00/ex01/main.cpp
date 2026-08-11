#include "PhoneBook.hpp"
#include <iostream> //for std

int	main(void)
{
	PhoneBook	phbook = PhoneBook();
	int			retu;

	std::cout << "Welcome to your phonebook!" << std::endl;
	retu = phbook.askCmd();
	return (retu);
}
