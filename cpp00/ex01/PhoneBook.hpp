#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

#define PHSIZE 8


class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();

		//accessors
		void	getContact(void);
		//helper
		void	printIndex(int delimiter);
		//cmds
		int		askCmd(void);
		void	search(void);
		void	add(void);

	private:
		Contact	_contacts[PHSIZE];
		int		_idx;


};

#endif

