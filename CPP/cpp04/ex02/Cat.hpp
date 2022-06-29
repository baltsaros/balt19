#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat: public	AAnimal {
	private:
		std::string	_type;
		Brain*		_brains;

	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);

		Cat&		operator=(Cat const &rhs);
		void		makeSound(void) const;
		void		getIdea(int i);
};

#endif