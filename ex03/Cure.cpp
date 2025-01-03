#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Cure copy constructor" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destroyed" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	// Noting to change
	if (this == &other)
		return *this;	
	return *this;
}

AMateria *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
