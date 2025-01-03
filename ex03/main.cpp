#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(void)
{
	Cure c;
	Floor f;
	Character bob("Bob", f);
	Character pat("Patrick", f);

	bob.equip(&c);
	bob.use(0, pat);
	bob.displayInventory();
	f.display();
	bob.unequip(0);
	f.display();

	return 0;
}