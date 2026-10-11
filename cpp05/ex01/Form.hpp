#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Form
{
	public:
		Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExec);
		Form(const Form& other);
		~Form();
		std::string	getName(void) const;
		unsigned int	getGradeToSign(void) const;
		unsigned int	getGradeToExec(void) const;
		bool				getSig(void) const;
		void				beSigned(unsigned int grade);
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

	private:
		const std::string	_name;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;
		bool				_sig;
		Form();//with const members default constructing is unwanted
		Form& operator=(const Form& other);
};

std::ostream&	operator<<(std::ostream& o, Form const& form);

#endif
