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
		bool		setFirstName(std::string fn);//TODO
		bool		setLastName(std::string  ln);//TODO
		bool		setNickName(std::string nn);//TODO
		bool		setPhoneNumber(std::string pn);//TODO
		bool		setDarkesSecret(std::string ds);//TODO
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

