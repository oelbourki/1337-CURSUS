#include "FragTrap.hpp"



FragTrap::FragTrap(std::string name)
{
    std::cout << "FR4G-TP " + this->name + "has been created" << std::endl;
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 100;
    this->max_energy_points = 100;
    this->level = 1;
    this->name = name;
    this->melee_attack_damage = 30;
    this->ranged_attack_damage = 20;
    this->armor_damage_reduction = 5;
}

FragTrap::FragTrap()
{
    std::cout << "a FR4G-TP has been created" << std::endl;
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 100;
    this->max_energy_points = 100;
    this->level = 1;
    this->name = "";
    this->melee_attack_damage = 30;
    this->ranged_attack_damage = 20;
    this->armor_damage_reduction = 5;
}

FragTrap::~FragTrap()
{
    std::cout << "FR4G-TP " + this->name + "has gone" << std::endl;
}

void    FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP " + this->name + " attacks " + target + " at range, causing ";
    std::cout << this->ranged_attack_damage;
    std::cout << " points of damage !" << std::endl;
}
void    FragTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP " + this->name + " attacks " + target + " with melee, causing ";
    std::cout << this->melee_attack_damage;
    std::cout << " points of damage !" << std::endl;
}
void    FragTrap::takeDamage(unsigned int amount)
{
    std::cout << "FR4G-TP " + this->name + " get damaged by an amount of " << std::endl;
    amount = amount - this->armor_damage_reduction;
   // if (amount <= 0)
    std::cout << amount;
    this->hit_points -= amount;
    if (this->hit_points <= 0)
        this->hit_points = 0;
}
void    FragTrap::beRepaired(unsigned int amount)
{
    std::cout << "FR4G-TP " + this->name + " being repared by an amount if" << std::endl;
    std::cout << amount;
    this->hit_points += amount;
    if (this->hit_points >= this->max_hit_points)
        this->hit_points = this->max_hit_points;
}

void    FragTrap::vaulthunter_dot_exe(std::string const & target)
{
    if (this->energy_points < 25)
    {
        std::cout << "not enough" << std::endl;
        return ;
    }
    this->energy_points -= 25;
    if (this->energy_points <= 0)
        this->energy_points = 0;
}