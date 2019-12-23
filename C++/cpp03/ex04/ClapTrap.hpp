#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        static int hit_points;
        static int max_hit_points;
        static int energy_points;
        static int max_energy_points;
        static int level;
        std::string name;
        static int melee_attack_damage;
        static int ranged_attack_damage;
        static int armor_damage_reduction;
    public:
        ClapTrap(const std::string name);
        ClapTrap();
        ~ClapTrap();
        void    rangedAttack(std::string const & target);
        void    meleeAttack(std::string const & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};
#endif