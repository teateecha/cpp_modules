#ifndef INTERN_HPP
#define INTERN_HPP
# include <string>
# include <exception>
class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		AForm*	makeForm(std::string name, std::string target);
		class NoSuchFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		AForm*	_createShrubbery(std::string target);
		AForm*	_createRobotomy(std::string target);
		AForm*	_createPardon(std::string target);
};

#endif

