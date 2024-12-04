#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		this->_type = other._type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Waf" << std::endl;
}

void Dog::mindRead() const
{
	for (int i = 0; i < 100; i++)
		std::cout << "Idea " << i + 1 << ": " << this->_brain->ideas[i] << std::endl;
}

void Dog::brainwash(int idea, std::string newIdea)
{
	if (idea > 0 && idea < 101)
		this->_brain->ideas[idea - 1] = newIdea;
	else
		std::cout << "Brainwash failed" << std::endl;
}
