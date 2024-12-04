#pragma once

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>
#include <unistd.h>

class Brain
{
	private:
		void _generateIdeas();
		std::string _getRandomIdea() const;

	public:
		std::string ideas[100];

		Brain();
		Brain(const Brain &other);
		~Brain();

		Brain &operator=(const Brain &other);
};
