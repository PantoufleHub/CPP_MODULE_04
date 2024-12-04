#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main(void)
{
	std::cout << " -- Creation: " << std::endl;
	Animal *animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Cat();
	for (int i = 5; i < 10; i++)
		animals[i] = new Dog();

	std::cout << std::endl << " -- Dynamic cast: " << std::endl;
	Cat c1 = *(dynamic_cast<Cat *>(animals[0]));
	Cat c2 = *(dynamic_cast<Cat *>(animals[3]));
	Dog d1 = *(dynamic_cast<Dog *>(animals[5]));

	std::cout << std::endl << " -- Sound: " << std::endl;
	c1.makeSound();
	d1.makeSound();

	std::cout << std::endl << " -- Copy: " << std::endl;
	c2 = c1;

	std::cout << std::endl << " -- Mind read: " << std::endl;
	c1.mindRead();
	c2.mindRead();

	std::cout << std::endl << " -- Brain washing... " << std::endl;
	c2.brainwash(1, "I want to be free");
	c2.brainwash(100, "I want to be free");

	std::cout << std::endl << " -- Post brain wash mind read: " << std::endl;
	c1.mindRead();
	c2.mindRead();

	std::cout << std::endl << " -- Delete: " << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << std::endl << " -- End: " << std::endl;
	return 0;
}
