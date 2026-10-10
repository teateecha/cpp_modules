#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;
		bool				_sig;
		Form();//with const members default constructing is unwanted
		Form& operator=(const Form& other);
		
	
	public:
		Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExec);
		Form(const Form& other);
		~Form();
		const std::string	getName(void) const;
		const unsigned int	getGradeToSign(void) const;
		const unsigned int	getGradeToExec(void) const;
		bool				getSig(void) const;
		void				beSigned(Bureaucrat buro);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& o, Form const& form);

#endif
