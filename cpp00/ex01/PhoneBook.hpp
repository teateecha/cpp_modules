#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
		Contact	*getContacts(void);
		//helper
		void	clear_space(std::string str)
		void	callCmd(std::string buff);//TODO
		//cmds
		void	search(Contact *contacts);//TODO
		void	add(Contact *contacts);//TODO


	private:
		Contact	_contacts[8];

};

#endif

