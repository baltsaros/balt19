#include "Warlock.hpp"

int	main(void) {
	// {
	// 	Warlock	bob;
	// 	Warlock	bob("Bob", "the magnificient");
	// 	Warlock	jim("Jim", "the nauseating");
	// 	Warlock	jack(jim);

	// 	bob = jim;
	// }
	{
		Warlock const richard("Richard", "Mistress of Magma");
		richard.introduce();
		std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

		Warlock* jack = new Warlock("Jack", "the Long");
		jack->introduce();
		jack->setTitle("the Mighty");
		jack->introduce();

		delete jack;

	}
	return (0);
}