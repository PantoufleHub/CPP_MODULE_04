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
	// std::cout << "Default materia source constructor" << std::endl;
	_init(other.getKnowledge());
}

MateriaSource::~MateriaSource()
{
	suppressKnowledge();
}

void MateriaSource::suppressKnowledge()
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

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	suppressKnowledge();
	_init(other.getKnowledge());
	return *this;
}

AMateria **MateriaSource::getKnowledge() const
{
	return ((AMateria **)this->_knowledge);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_knowledge[i])
		{
			this->_knowledge[i] = materia;
			std::cout << "Source has learned " << materia->getType() << " materia." << std::endl;
			break;
		}
		else if (i == 3)
		{
			delete materia;
			std::cout << "No more space to learn new materia, materia destroyed" << std::endl;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_knowledge[i]->getType() == type)
		{
			return this->_knowledge[i]->clone();
			break;
		}
		else if (i == 3)
			std::cout << "Unknown materia type \"" << type << "\"." << std::endl;
	}
	return NULL;
}

