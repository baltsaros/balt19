#ifndef FRAGTRAP_HPP
# define	FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
	private:

	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap&	operator=(FragTrap const &rhs);
		void		highFivesGuys(void);
		void		highFivesGuys(ClapTrap& target);
		void		attack(const std::string& target);
		void		attack(ClapTrap& target);
};

#endif