
#include "SuperTrap.hpp"



SuperTrap::SuperTrap(std::string name)
{
    // ClapTrap(name , 100, 100, 120, 120 ,1, 30 , 20, 5);
}

SuperTrap::SuperTrap()
{
    std::cout << "a Super-TP has been created" << std::endl;
    this->hit_points = 60;
    this->max_hit_points = 60;
    this->energy_points = 120;
    this->max_energy_points = 120;
    this->level = 1;
    this->name = "";
    this->melee_attack_damage = 60;
    this->ranged_attack_damage = 5;
    this->armor_damage_reduction = 0;
}

SuperTrap::~SuperTrap()
{
    std::cout << "Super-TP " + this->name + "has gone" << std::endl;
}

void    SuperTrap::rangedAttack(std::string const & target)
{
    FragTrap::rangedAttack(target);
}
void    SuperTrap::meleeAttack(std::string const & target)
{
    NinjaTrap::meleeAttack(target);
}
void    SuperTrap::takeDamage(unsigned int amount)
{
    std::cout << "Super-TP " + this->name + " get damaged by an amount of " << std::endl;
    amount = amount - this->armor_damage_reduction;
    std::cout << amount;
    this->hit_points -= amount;
    if (this->hit_points <= 0)
        this->hit_points = 0;
}
void    SuperTrap::beRepaired(unsigned int amount)
{
    std::cout << "Super-TP " + this->name + " being repared by an amount if" << std::endl;
    std::cout << amount;
    this->hit_points += amount;
    if (this->hit_points >= this->max_hit_points)
        this->hit_points = this->max_hit_points;
}
