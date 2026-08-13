#include "PhoneBook.hpp"
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setfill, std::setw
#include <cstring>		// std::c_str
#include <string>		// std::string,
#include <stdlib.h>		// atoi


PhoneBook::PhoneBook() : idx(0)
{
	std::cout << "Phonebook: Constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook: Destructor called" << std::endl;
}

//accessors
// void	PhoneBook::setContact(Contact entry)
// {
// 	this->_contacts[idx % 8] = entry;
// }

//helper: removes spaces and tabs
static std::string	clear_space(std::string str)
{
	for(int i = str.length() - 1; i >= 0; i--)
		if (str[i] == ' ' || str [i] == '\t')
			str.erase(i, 1);
	return (str);
}

//helper: writes prompts and returns inputstring without spaces
static std::string	waitInput(std::string text)
{
	std::string	buff;

	while(buff.empty())
	{
		std::cout << text << " ";
		std::getline(std::cin, buff);
	}
	clear_space(buff);
	return (buff);
}

// commands:
int	PhoneBook::askCmd(void)
{
	std::string	cmd;

	while (1)
	{
		cmd = waitInput("Please write: Do you want to ADD, SEARCH or EXIT?");
		if (cmd == "ADD")
			this->add();
		else if (cmd == "SEARCH")
			this->search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "no match. try again" << std::endl;
	}
	return (0);
}

void	PhoneBook::add(void)
{
	if(!_contacts[idx % 8].setFirstName(waitInput("First Name: ")))
		return ;
	if(!_contacts[idx % 8].setLastName(waitInput("Last Name: ")))
		return ;
	if(!_contacts[idx % 8].setNickName(waitInput("Nick Name: ")))
		return ;
	if(!_contacts[idx % 8].setPhoneNumber(waitInput("Phone Number: ")))
		return ;
	if(!_contacts[idx % 8].setDarkestSecret(waitInput("Darkest Secret: ")))
		return ;
	idx++;
}

//helper
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

void	PhoneBook::search(void)
{
	int			nbr;
	std::string	index;
	std::cout << std::left << std::setw(10);
	std::cout << "index";
	putTruncated("first name");
	putTruncated("last name");
	putTruncated("nickname");
	std::cout << std::endl;
	for  (int i = 0; i < 8; i++)
	{
		std::cout << std::left << std::setw(10);
		std::cout << i;
		putTruncated(_contacts[i].getFirstName());
		putTruncated(_contacts[i].getLastName());
		putTruncated(_contacts[i].getNickName());
		std::cout << std::endl;
	}
	while (1)
	{
		index = waitInput("Insert index of Contact to display");
		nbr = atoi(index.c_str());
		if (nbr < 0 || nbr > 7)
			std::cout << "wrong input try again" << std::endl;
		else
			break;
	}
	_contacts[nbr].displayDetails();
}
