#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"
#include <iostream>

class Character : public ICharacter
{
	private:
		std::string _name;
		Floor *_floor;
		AMateria *_inventory[4];
		void _init(std::string name, Floor *floor, AMateria **inv);

	public:
		Character();
		Character(std::string name, Floor &floor);
		Character(const Character &other);
		~Character();

		Character &operator=(const Character &other);

		Floor *getFloor() const;
		AMateria **getInventory() const;
		std::string const &getName() const;

		void setFloor(Floor &floor);

		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

		// void displayFloor() const;
		void displayInventory() const;
};