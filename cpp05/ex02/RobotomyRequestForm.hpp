#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>

class RobotomyRequestForm
{
	private:
		std::string	_name;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
};

#endif
