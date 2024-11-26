#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	// *this = other;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

// WrongCat &WrongCat::operator=(const WrongCat &other)
// {
// 	if (this != &other)
// 		this->_type = other._type;

// 	return *this;
// }

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow" << std::endl;
}
