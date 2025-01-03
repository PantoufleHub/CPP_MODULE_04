#pragma once

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice(const Ice &other);
		~Ice();

		Ice &operator=(const Ice &other);

		AMateria *clone() const;
		void use(ICharacter &target);
};
