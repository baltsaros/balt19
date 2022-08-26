/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:47:38 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 15:47:39 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	one("Toto");
	ScavTrap	four("Gi");
	std::string	target;

	target = "Jo";
	std::cout << YLWB "\n+++++ STANDARD TESTS +++++\n";
	four.guardGate();
	one.approach();
	four.attack(one);
	four.attack(one);
	four.beRepaired(1);

	std::cout << YLWB "\n+++++ SOME EXTRA TESTS +++++\n";
	ClapTrap	two("Jo");
	ClapTrap	three(two);
	ScavTrap	five(four);
	ScavTrap	six;

	two = one;
	five = six;
	std::cout << "New name of Jo is " << two.getName() << std::endl;
	std::cout << std::endl;
	return (0);
}
