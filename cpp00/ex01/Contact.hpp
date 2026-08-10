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
		std::string	getDarkesSecret(void);//TODO
		std::string	getFirstName(void);//TODO
		void	setContact(std::string fn,
					std::string ln,
					std::string nn,
					std::string pn,
					std::string ds);
		void	displayIndex(void);//TODO
		void	displayDetails(int idx);//TODO

    private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif

