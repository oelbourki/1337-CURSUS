#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#pragma once
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
        // ClapTrap(const std::string name, int hit_points,int max_hit_points,
        // int energy_points,int max_energy_points,int level, int melee_attack_damage,
        // int ranged_attack_damage, int armor_damage_reduction);
        ClapTrap();
        ~ClapTrap();
        void    rangedAttack(std::string const & target);
        void    meleeAttack(std::string const & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};
#endif