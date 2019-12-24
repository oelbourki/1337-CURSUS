#include <iostream>
#pragma once
class ClapTrap
{
    protected:
        int hit_points;
        int max_hit_points;
        int energy_points;
        int max_energy_points;
        int level;
        std::string name;
        int melee_attack_damage;
        int ranged_attack_damage;
        int armor_damage_reduction;
    public:
        ClapTrap(std::string name);
        ClapTrap();
        ~ClapTrap();
        ClapTrap(const std::string name, int hit_points,int max_hit_points,
        int energy_points,int max_energy_points,int level, int melee_attack_damage,
        int ranged_attack_damage, int armor_damage_reduction);
        void    rangedAttack(std::string const & target);
        void    meleeAttack(std::string const & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};