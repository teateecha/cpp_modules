#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
    public:
        Contact();
        ~Contact();
		std::string	getFirstName(void);//TODO
		std::string	getLastName(void);//TODO
		std::string	getNickName(void);//TODO
		std::string	getPhoneNumber(void);//TODO
		std::string	getDarkestSecret(void);//TODO
		bool		setFirstName(std::string fn);
		bool		setLastName(std::string  ln);
		bool		setNickName(std::string nn);
		bool		setPhoneNumber(std::string pn);
		bool		setDarkestSecret(std::string ds);
		void		displayIndex(void);//TODO
		void		displayDetails(int idx);//TODO

    private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif

