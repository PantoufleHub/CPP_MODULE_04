#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain summoned" << std::endl;
	_generateIdeas();
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
		// std::cout << "Copying idea " << i + 1 << ": " << this->ideas[i] << std::endl;
	}
	return *this;
}

std::string Brain::_getRandomIdea() const
{
	std::string idea;
	static int test = 0;

	std::string idea_fragment1[] = {"Me", "Brain", "I", "Why"};
	std::string idea_fragment2[] = {"want", "have"};
	std::string idea_fragment3[] = {"toy", "fun", "food", "water", "drink"};
	std::string *idea_fragments[3] = {idea_fragment1, idea_fragment2, idea_fragment3};
	int sizes[3] = {4, 2, 5};

	for (int x = 0; x < 3; x++)
	{
		srand(static_cast<unsigned int>(time(NULL)) + getpid() + test);
		test += rand();
		idea += idea_fragments[x][(rand() % sizes[x])];
		if (x < 2)
			idea += " ";
	}
	// std::cout << "New idea " << idea << std::endl;
	return idea;
}

void Brain::_generateIdeas()
{
	for (int nb = 0; nb < 100; nb++)
	{
		this->ideas[nb] = _getRandomIdea();
	}
}
