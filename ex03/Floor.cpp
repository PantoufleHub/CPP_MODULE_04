#include "Floor.hpp"

void Floor::_init(AMateria **onFloor)
{
	for (int i = 0; i < 10; i++)
	{
		if (!onFloor)
			this->onFloor[i] = NULL;
		else	
			this->onFloor[i] = onFloor[i];
	}
}

Floor::Floor()
{
	// std::cout << "Floor default constructor" << std::endl;
	_init(NULL);
}

Floor::Floor(const Floor &other)
{
	// std::cout << "Floor copy constructor" << std::endl;
	_init(other.getOnFloor());
}

Floor::~Floor()
{
	for (int i = 0; i < 10; i++)
	{
		if (this->onFloor[i])
		{
			delete this->onFloor[i];
			this->onFloor[i] = NULL;
		}
	}
}

Floor &Floor::operator=(const Floor &other)
{
	for (int i = 0; i < 10; i++)
	{
		if (this->onFloor[i])
			delete this->onFloor[i];
		this->onFloor[i] = other.getOnFloor()[i];
	}
	return *this;
}

AMateria **Floor::getOnFloor() const
{
	return (AMateria **)this->onFloor;
}

void Floor::remove(unsigned int materiaId)
{
	std::cout << "removing materia " << materiaId << std::endl; 
	this->onFloor[materiaId] = NULL;
}

void Floor::add(AMateria &materia)
{
	int foundSpace = 0;

	for (int i = 0; i < 10; i++)
	{
		if (this->onFloor[i] == NULL)
		{
			this->onFloor[i] = &materia;
			foundSpace = 1;
			break;
		}
	}
	if (!foundSpace)
	{
		std::cout << "The floor is already covered in materia, destroying materia >:(" << std::endl;
		delete &materia;
	}
}

void Floor::display() const
{
	std::cout << "Floor: " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (this->onFloor[i])
			std::cout << i << " | " << this->onFloor[i]->getType() << " |" << std::endl;
		else
			std::cout << i << " | empty | " << std::endl;
	}
}
