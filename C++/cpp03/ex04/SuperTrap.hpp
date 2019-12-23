#include <iostream>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#pragma once
class SuperTrap : public NinjaTrap , public FragTrap
{
    public:
        SuperTrap(std::string name);
        SuperTrap();
        ~SuperTrap();
        void    rangedAttack(std::string const & target);
        void    meleeAttack(std::string const & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    ninjaShoebox(FragTrap const &target);
        void    ninjaShoebox(ScavTrap const &target);
};