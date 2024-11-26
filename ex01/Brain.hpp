#pragma once

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>
#include <unistd.h>

class Brain
{
	private:
		std::string _ideas[100];
		void _generateIdeas();
		std::string _getRandomIdea() const;

	public:
		Brain();
		Brain(const Brain &other);
		~Brain();

		Brain &operator=(const Brain &other);
};
