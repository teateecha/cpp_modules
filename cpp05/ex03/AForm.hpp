#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <ostream>
# include <exception>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExec);
		AForm& operator=(const AForm& other);
		AForm(const AForm& other);
		virtual ~AForm();
		std::string		getName(void) const;
		unsigned int	getGradeToSign(void) const;
		unsigned int	getGradeToExec(void) const;
		bool			getSig(void) const;
		void			beSigned(Bureaucrat const& buro);
		void			execute(Bureaucrat const& buro) const;
		virtual void	action(void) const = 0;
		
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
		class NotSigndException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;
		bool				_sig;
};

std::ostream&	operator<<(std::ostream& o, AForm const& form);

#endif
