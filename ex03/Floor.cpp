#include "Floor.hpp"

void Floor::_init(AMateria *onFloor)
{
	this->onFloor = onFloor;
}

Floor::Floor()
{
	std::cout << "Floor default constructor" << std::endl;
	_init(NULL);
}

Floor::Floor(const Floor &other)
{
	std::cout << "Floor copy constructor" << std::endl;
	_init(other.getOnFloor());
}

Floor::~Floor()
{
	// b;a a;df;s clear
}

Floor &Floor::operator=(const Floor &other)
{
	// bla laalksd
	other.display();
	return *this;
}

AMateria *Floor::getOnFloor() const
{
	return this->onFloor;
}

void Floor::remove(unsigned int materiaId)
{
	// sdfasdf
	std::cout << "removing materia " << materiaId << std::endl; 
}

void Floor::add(AMateria &materia)
{
	// dskfj;alksdjf;dk
	materia.getType();
}

void Floor::display() const
{
	std::cout << "Floor display" << std::endl;
}
