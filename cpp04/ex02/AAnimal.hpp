#ifndef AANIMAL_HPP
#define AANIMAL_HPP
# include <string>//for std::string

// abstract Class cannot be instenciated
class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		// virtual so deleting through AAnimal* calls the derived Destructor first
		virtual	~AAnimal();

		std::string	getType(void) const;
		//enable runtime polymorphism: AAnimal* calles the derived makeSound()
		virtual void	makeSound(void) const = 0; // this makes the method pure and the class abstract.
		
	protected:
		std::string		_type;
};

#endif

