#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice constructor" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	// std::cout << "Ice copy constructor" << std::endl;
}

Ice::~Ice()
{
	// std::cout << "Ice destroyed" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	// Noting to change
	if (this == &other)
		return *this;	
	return *this;
}

AMateria *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
