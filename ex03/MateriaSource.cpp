#include "MateriaSource.hpp"

void MateriaSource::_init(AMateria **knowledge)
{
	for (int i = 0; i < 4; i++)
	{
		if (!knowledge)
			this->_knowledge[i] = NULL;
		else
			this->_knowledge[i] = knowledge[i];
	}
}

MateriaSource::MateriaSource()
{
	std::cout << "Default materia source constructor" << std::endl;
	_init(NULL);
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "Default materia source constructor" << std::endl;
	_init(other.getKnowledge());
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_knowledge[i])
		{
			delete this->_knowledge[i];
			this->_knowledge[i] = NULL;
		}
	}
}

AMateria **MateriaSource::getKnowledge() const
{
	return ((AMateria **)this->_knowledge);
}

// implement imateriasource
