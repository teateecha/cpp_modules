#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
# include <string>

class GradeTooHighException : public std::exception
{
	public:
		virtual const char* what() const throw();//this functions does not throw
};

class GradeTooLowException : public std::exception
{
	public:
		virtual const char* what() const throw();//this functions does not throw
};

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string	getName(void);
		unsigned int		getGrade(void);
		GradeTooHighException	th;
		GradeTooLowException	tl;

	private:
		Bureaucrat();//grade is mandatory for instatuation
		const std::string	_name;
		unsigned int	_grade;
};

#endif
