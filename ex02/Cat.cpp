#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

void Cat::mindRead() const
{
	for (int i = 0; i < 100; i++)
		std::cout << "Idea " << i + 1 << ": " << this->_brain->ideas[i] << std::endl;
}

void Cat::brainwash(int idea, std::string newIdea)
{
	if (idea > 0 && idea < 101)
		this->_brain->ideas[idea - 1] = newIdea;
	else
		std::cout << "Brainwash failed" << std::endl;
}