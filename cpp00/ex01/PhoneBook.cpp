#include "PhoneBook.hpp"
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setfill, std::setw
#include <cstring>		// std::c_str
#include <string>		// std::string,
#include <stdlib.h>		// atoi
#include <cctype>		//isdigit


PhoneBook::PhoneBook() : _idx(0)
{
	std::cout << "PhoneBook: Constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook: Destructor called" << std::endl;
}

///helper: Removes leading and trailing spaces and tabs from a string.
static std::string	clear_space(std::string str)
{
	size_t	start;
	size_t	end;

	start = str.find_first_not_of(" \t");
	if (start == std::string::npos)//end of string
		return ("");
	end = str.find_last_not_of(" \t");

	return (str.substr(start, end - start + 1));
}

/// helper: Prompts untill non-empty input removes surrounding whitespace.
static std::string	waitInput(std::string text)
{
	std::string	buff;

	while(buff.empty())
	{
		std::cout << text << " ";
		std::getline(std::cin, buff);
	}
	buff = clear_space(buff);
	return (buff);
}

// commands:
/// Repeatedly asks for and executes the ADD, SEARCH, or EXIT command.
int	PhoneBook::askCmd(void)
{
	std::string	cmd;

	while (1)
	{
		cmd = waitInput("Please enter ADD, SEARCH or EXIT");
		if (cmd == "ADD")
			this->_add();
		else if (cmd == "SEARCH")
			this->_search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "No match. Try again" << std::endl;
	}
	return (0);
}

/// Reads a new contact from user input and stores it in the phone book.
void	PhoneBook::_add(void)
{
	if(!_contacts[_idx % PHSIZE].setFirstName(waitInput("First Name: ")))
		return ;
	if(!_contacts[_idx % PHSIZE].setLastName(waitInput("Last Name: ")))
		return ;
	if(!_contacts[_idx % PHSIZE].setNickName(waitInput("Nickname: ")))
		return ;
	while(!_contacts[_idx % PHSIZE].setPhoneNumber(waitInput("Phone Number: ")));
	if(!_contacts[_idx % PHSIZE].setDarkestSecret(waitInput("Darkest secret: ")))
		return ;
	_idx++;
}

///helper: Prints a string in a 10-character field and truncates longer strings with a dot.
static void	putTruncated(std::string str)
{
	std::cout << "|";
	if (str.empty() || str.length() < 10)
	{
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << str;
	}
	else if (str.length() == 10)
	{
		std::cout << str;
	}
	else
		std::cout << str.substr(0,9) << ".";
}

/// Displays the contact list as a formatted table up to the given number of entries.
void	PhoneBook::printIndex(int delimiter)
{
	std::cout << std::left << std::setw(10);
	std::cout << "index";
	putTruncated("first name");
	putTruncated("last name");
	putTruncated("nickname");
	std::cout << std::endl;

	for  (int i = 0; i < delimiter; i++)
	{
		std::cout << std::left << std::setw(10);
		std::cout << i;
		putTruncated(_contacts[i].getFirstName());
		putTruncated(_contacts[i].getLastName());
		putTruncated(_contacts[i].getNickName());
		std::cout << std::endl;
	}

}

/// Displays the contact table, asks for a valid index, and shows the selected contact.
void	PhoneBook::_search(void)
{
	int			nbr;
	std::string	index;
	int	delimiter;

	if (_idx < PHSIZE)
		delimiter = _idx;
	else
		delimiter = PHSIZE;

	this->printIndex(delimiter);
	while (_idx > 0)
	{
		index = waitInput("Enter index of the contact to display");
		nbr = atoi(index.c_str());
		if (index.length() > 1 || !isdigit(index[0]) || nbr < 0 || delimiter  <= nbr)
			std::cout << "Wrong input. Try again." << std::endl;
		else
			break;
	}
	if (_idx > 0)
		_contacts[nbr].displayDetails();
	else
		std::cout << "Your phonebook is empty" << std::endl;
}
