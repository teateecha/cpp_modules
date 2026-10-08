#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
# include <string>

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;
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
		void	increment(void);
		void	decrement(void);
		
	private:
		Bureaucrat& operator=(const Bureaucrat& other);//should not be used with const
		Bureaucrat();//grade is mandatory for instatuation
		const std::string	_name;
		unsigned int	_grade;
};

#endif
