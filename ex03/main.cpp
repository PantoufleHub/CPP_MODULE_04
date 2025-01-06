#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(void)
{
	std::cout << "-- Init" << std::endl;
	Floor f;
	MateriaSource s;
	Character c1("Bob", f);
	Character c2("Patrick", f);

	std::cout << "\n-- Materia source" << std::endl;
	s.learnMateria(new Ice());
	s.learnMateria(new Cure());
	s.learnMateria(new Cure());
	s.learnMateria(new Ice());
	s.learnMateria(new Ice());
	s.learnMateria(new Cure());
	s.learnMateria(new Ice());

	std::cout << "\n-- Bob equip" << std::endl;
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

	std::cout << "\n-- Bob use" << std::endl;
	c1.use(0, c2);
	c1.use(1, c2);
	c1.use(-10, c2);
	c1.use(10, c2);

	std::cout << "\n-- Patrick" << std::endl;
	c2.use(0, c1);

	c2.equip(f.getOnFloor()[5]);
	f.remove(5);

	c2.displayInventory();
	f.display();

	c2.use(0, c1);

	c2.unequip(0);
	f.display();

	// -- Test from subject -- (with floor)
	// Floor *f = new Floor();
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me", *f);
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob", *f);
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	// delete f;

	return 0;
}