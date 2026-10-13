#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>
# include <exception>

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExec);
		AForm(const AForm& other);
		virutal ~AForm();
		std::string		getName(void) const;
		unsigned int	getGradeToSign(void) const;
		unsigned int	getGradeToExec(void) const;
		bool				getSig(void) const;
		void				beSigned(Bureaucrat& buro);
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
		AForm();//with const members default constructing is unwanted
		AForm& operator=(const AForm& other);//same for copying
};

std::ostream&	operator<<(std::ostream& o, AForm const& form);

#endif
