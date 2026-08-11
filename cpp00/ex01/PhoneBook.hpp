#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact"

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
		void	setContact(int idx);
		void	getContact(int idx)

	private:
		Contact	_contacts[8];

};

#endif

