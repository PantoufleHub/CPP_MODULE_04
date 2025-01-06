#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"


int main(void)
{
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	const Animal *a = new Animal();

	const Animal* d = new Dog();
	const Animal* c = new Cat();
	
	std::cout << std::endl;

	std::cout << wa->getType() << " " << std::endl;
	std::cout << wc->getType() << " " << std::endl;
	std::cout << a->getType() << " " << std::endl;
	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;

	std::cout << std::endl;

	wa->makeSound();
	wc->makeSound();
	a->makeSound();
	d->makeSound();
	c->makeSound();

	std::cout << std::endl;

	delete wa;
	delete wc;
	delete a;
	delete d;
	delete c;
	
	return 0;
}