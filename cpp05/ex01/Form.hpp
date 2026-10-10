#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Form
{
	private:
		const std::string	_name;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;
		bool				_sig;
		
	
	public:
		Form();
		Form(std::string name);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		const std::string	getName(void) const;
		const unsigned int	getGradeToSign(void);
		const unsigned int	getGradeToExec(void);
		bool				getSig(void);
		bool				setSig(bool sig);
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
