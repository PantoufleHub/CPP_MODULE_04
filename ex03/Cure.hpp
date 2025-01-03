#pragma once

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
	private:

	public:
		Cure();
		Cure(const Cure &other);
		~Cure();

		Cure &operator=(const Cure &other);

		AMateria *clone() const;
		void use(ICharacter &target);
};
