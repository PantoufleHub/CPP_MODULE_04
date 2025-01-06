#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(void)
{
	Floor f;
	MateriaSource s;
	Character c1("Bob", f);
	Character c2("Patrick", f);

	s.learnMateria(new Ice());
	s.learnMateria(new Cure());
	s.learnMateria(new Cure());
	s.learnMateria(new Ice());
	s.learnMateria(new Ice());
	s.learnMateria(new Cure());
	s.learnMateria(new Ice());

	c1.equip(s.createMateria("ice"));
	c1.equip(s.createMateria("cure"));
	c1.equip(s.createMateria("cure"));
	c1.equip(s.createMateria("ice"));
	c1.equip(s.createMateria("cure"));
	c1.equip(s.createMateria("cure"));
	c1.equip(s.createMateria("cure"));
	c1.equip(s.createMateria("cure"));
	c1.equip(s.createMateria("ice"));
	c1.equip(s.createMateria("ice"));
	c1.equip(s.createMateria("ice"));
	c1.equip(s.createMateria("ice"));
	c1.equip(s.createMateria("cure"));
	c1.equip(s.createMateria("cure"));
	c1.equip(s.createMateria("cure"));
	c1.equip(s.createMateria("ice"));

	c1.displayInventory();
	f.display();

	c1.use(0, c2);
	c1.use(1, c2);
	c1.use(-10, c2);
	c1.use(10, c2);

	c2.use(0, c1);

	return 0;
}