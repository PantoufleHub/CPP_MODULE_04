#include "Character.hpp"

void Character::_init(std::string name, Floor *floor, AMateria **inv)
{
	this->_name = name;
	this->_floor = floor;
	for (int i = 0; i < 4; i++)
	{
		if (!inv || !inv[i])
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = inv[i]->clone();
	}
}

Character::Character()
{
	std::cout << "Default character created in a seperate universe?" << std::endl;
	_init("Blake? idk", NULL, NULL);
}

Character::Character(std::string name, Floor &floor)
{
	std::cout << "Creating character " << name << std::endl;
	_init(name, &floor, NULL);
}

Character::Character(const Character &other)
{
	std::cout << "Copying character..." << other .getName() << std::endl;
	_init(other.getName(), other.getFloor(), other.getInventory());
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Copying " << other.getName() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = other.getInventory()[i]->clone();
	}
	this->_name = other.getName();
	this->_floor = other.getFloor();
	return *this;
}

Floor *Character::getFloor() const
{
	return this->_floor;
}

AMateria **Character::getInventory() const
{
	return (AMateria **)(this->_inventory);
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::setFloor(Floor &floor)
{
	this->_floor = &floor;
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Tried to equip an inexistant materia" << std::endl;
		return ;
	}

	int i = 0;
	while (i < 4 && this->_inventory[i])
		i++;

	if (i > 3)
		std::cout << "No space in inventory." << std::endl;
	else
	{
		this->_inventory[i] = m;
		std::cout << "Equipped " << m->getType() << " in slot " << i << std::endl;
	}

}

void Character::unequip(int idx)
{
	if (idx < 0 && idx > 3)
	{
		std::cout << "Invalid slot number" << std::endl;
		return ;
	}

	if (!this->_inventory[idx])
	{
		std::cout << "Tried to unequip empty slot" << std::endl;
		return ;
	}

	this->_floor->add(*this->_inventory[idx]);
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 && idx > 3)
	{
		std::cout << "Invalid slot number" << std::endl;
		return ;
	}

	if (!this->_inventory[idx])
	{
		std::cout << "Tried to cast empty slot" << std::endl;
		return ;
	}

	this->_inventory[idx]->use(target);
}

void Character::displayInventory() const 
{
	std::cout << this->_name << "'s inventory:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			std::cout << "Slot " << i << ": " << this->_inventory[i]->getType() << std::endl;
		else
			std::cout << "Slot " << i << ": empty" << std::endl;
	}
	std::cout << "-----------------" << std::endl;
}
