#include "Animal.hpp"

Animal::Animal() : _type("Unknown Animal") 
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) 
{
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal ()
{
	std::cout << "Default Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound() const
{
	std::cout << "*Unknown animal sound*" << std::endl;
}
