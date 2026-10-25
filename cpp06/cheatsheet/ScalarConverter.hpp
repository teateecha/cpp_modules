#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	private:
		std::string	_name;
	
	public:
		ScalarConverter();
		ScalarConverter(std::string name);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
};

#endif
