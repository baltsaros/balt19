#ifndef SCAVTRAP_HPP
# define	SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	private:
		std::string		_name;
		int				_hp;
		int				_ep;
		unsigned int	_ad;

	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);

		ScavTrap&	operator=(ScavTrap const &rhs);
		void		guardGate(void);
		void		attack(const std::string& target);
		void		attack(ClapTrap& target);
};

#endif