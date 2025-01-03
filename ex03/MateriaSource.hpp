#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : IMateriaSource
{
	private:
		AMateria *_knowledge[4];
		void _init(AMateria **knowledge);
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();

		AMateria **getKnowledge() const;
};
