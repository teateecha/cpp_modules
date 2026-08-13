#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    public:
		int		idx;
        PhoneBook();
        ~PhoneBook();

		//cmds
		int		askCmd(void);
		void	search();//TODO
		void	add();//TODO
		//accessors
		// void	setContact(Contact entry);
		void	getContact();

	private:
		Contact	_contacts[8];

};

#endif

