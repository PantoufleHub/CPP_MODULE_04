#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Unknown") 
{
	std::cout << "Default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) 
{
	std::cout << "AAnimal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = other;
}

AAnimal::~AAnimal ()
{
	std::cout << "Default AAnimal destructor called" << std::endl;
}

// AAnimal &AAnimal::operator=(const AAnimal &other)
// {
// 	if (this != &other)
// 		this->_type = other._type;
// 	return *this;
// }

std::string AAnimal::getType() const
{
	return this->_type;
}

void AAnimal::makeSound() const
{
	std::cout << "*Unknown AAnimal sound*" << std::endl;
}
