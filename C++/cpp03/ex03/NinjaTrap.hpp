#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class NinjaTrap : public ClapTrap
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
};