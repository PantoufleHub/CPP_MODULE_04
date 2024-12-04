#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *_brain;

	public:
		Dog();
		Dog(const Dog &other);
		virtual ~Dog();

		Dog &operator=(const Dog &other);

		void makeSound() const;
		void mindRead() const;
		void brainwash(int idea, std::string newIdea);
};