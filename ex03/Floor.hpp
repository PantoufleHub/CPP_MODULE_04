#pragma once

#include <iostream>
#include "AMateria.hpp"

class Floor
{
	private:
		AMateria *onFloor;
		void _init(AMateria *onFloor);

	public:
		Floor();
		Floor(const Floor &other);
		~Floor();

		Floor &operator=(const Floor &other);

		AMateria *getOnFloor() const;

		void remove(unsigned int materiaId);
		void add(AMateria &materia);

		void display() const;
};