#include "PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook() : idx(0)
{
	std::cout << "Phonebook: Constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << firstName << ": Destructor called" << std::endl;
}

//accessors
void	PhoneBook::setContact(Contact entry)
{
	this->_contacts[idx % 8] = entry;
}



//helper: removes spaces and tabs
static std::string	clear_space(std::string str)
{
	for(int i = str.length() - 1, i >= 0, i--)
		if (str[i] == ' ' || str [i] == '\t')
			str.erase(i, 1);
}

//helper: writes prompts and returns inputstring without spaces
static std::string	waitInput(std:string text)
{
	std::string	buff;

	while(buff.empty())
	{
		std::cout << text;
		std::getline(std::cin, buff);
	}
	clear_space(buff);
	return (buff);
}

//sets to 10 char string


// commands:
int	PhoneBook::askCmd();
{
	std::string	cmd;

	while (1)
	{
		cmd = waitInput("Please write: Do you want to ADD, SEARCH or EXIT?");
		if (cmd == "ADD")
			this.add();
		else if (cmd == "SEARCH")
			this.search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "no match. try again" << std::endl;
	}
	return (0);
}

void	PhoneBook::add(void)
{
	Contact	entry = Contact();

	if(!entry.setFirstName(waitInput("First Name: ")))
		return ;
	if(!entry.setLastName(waitInput("Last Name: ")))
		return ;
	if(!entry.setNickName(waitInput("Nick Name: ")))
		return ;
	if(!entry.setPhoneNumber(waitInput("Phone Number: ")))
		return ;
	if(!entry.setDarkestSecret(waitInput("Darkest Secret: ")))
		return ;
	setContact(entry);
	idx++;
}


void	PhoneBook::search(void)
{
	int		i;
	Contact	entry;



}
