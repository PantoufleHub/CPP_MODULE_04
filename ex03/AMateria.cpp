#include "AMateria.hpp"

AMateria::AMateria()
{
	// std::cout << "AMateria constructor" << std::endl;
	this->_type = "dark magic";
}

AMateria::AMateria(std::string const &type)
{
	// std::cout << "AMateria name constructor" << std::endl;
	this->_type = type;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destroyed" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this == &other)
		return *this;
		
	this->_type = other.getType();
	return *this;
}

const std::string &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "The spell does absolutely nothing to " << target.getName() << std::endl;
}
