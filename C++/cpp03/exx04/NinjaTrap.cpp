#include "NinjaTrap.hpp"



NinjaTrap::NinjaTrap(std::string name)
{
    std::cout << "Ninja-TP " + this->name + "has been created" << std::endl;
    this->hit_points = 60;
    this->max_hit_points = 60;
    this->energy_points = 120;
    this->max_energy_points = 120;
    this->level = 1;
    this->name = name;
    this->melee_attack_damage = 60;
    this->ranged_attack_damage = 5;
    this->armor_damage_reduction = 0;
}

NinjaTrap::NinjaTrap()
{
    std::cout << "a Ninja-TP has been created" << std::endl;
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

NinjaTrap::~NinjaTrap()
{
    std::cout << "Ninja-TP " + this->name + "has gone" << std::endl;
}

void    NinjaTrap::rangedAttack(std::string const & target)
{
    std::cout << "Ninja-TP " + this->name + " attacks " + target + " at range, causing ";
    std::cout << this->ranged_attack_damage;
    std::cout << " points of damage !" << std::endl;
}
void    NinjaTrap::meleeAttack(std::string const & target)
{
    std::cout << "Ninja-TP " + this->name + " attacks " + target + " with melee, causing ";
    std::cout << this->melee_attack_damage;
    std::cout << " points of damage !" << std::endl;
}
void    NinjaTrap::takeDamage(unsigned int amount)
{
    std::cout << "Ninja-TP " + this->name + " get damaged by an amount of " << std::endl;
    amount = amount - this->armor_damage_reduction;
   // if (amount <= 0)
    std::cout << amount;
    this->hit_points -= amount;
    if (this->hit_points <= 0)
        this->hit_points = 0;
}
void    NinjaTrap::beRepaired(unsigned int amount)
{
    std::cout << "Ninja-TP " + this->name + " being repared by an amount if" << std::endl;
    std::cout << amount;
    this->hit_points += amount;
    if (this->hit_points >= this->max_hit_points)
        this->hit_points = this->max_hit_points;
}

void    NinjaTrap::ninjaShoebox(FragTrap const &target)
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

void    NinjaTrap::ninjaShoebox(ScavTrap const &target)
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