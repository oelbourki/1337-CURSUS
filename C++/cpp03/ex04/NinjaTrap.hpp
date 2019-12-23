#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual ClapTrap
{
    public:
        NinjaTrap(std::string name);
        NinjaTrap();
        ~NinjaTrap();
        void    rangedAttack(std::string const & target);
        void    meleeAttack(std::string const & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    ninjaShoebox(FragTrap const &target);
        void    ninjaShoebox(ScavTrap const &target);
        void    ninjaShoebox(NinjaTrap const &target);
};
#endif