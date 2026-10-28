#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

# define TRUE 1
# define FALSE 0

class ScalarConverter
{
	public:
		ScalarConverter&	operator=(const ScalarConverter& other);
		~ScalarConverter();
		static void	convert(std::string input);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& oher);
};

typedef enum e_type
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID,
} t_type;

#endif
