#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		const std::string*	getIdeaAddress(int i) const;
	private:
		std::string	_ideas[100];
};

#endif

