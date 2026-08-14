#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

#define PHSIZE 8


class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();

		int		askCmd(void);

	private:
		Contact	_contacts[PHSIZE];
		int		_idx;
		void	_search(void);
		void	_add(void);
		void	_printIndex(int delimiter);


};

#endif

