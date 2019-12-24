#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name, int hit_points,int max_hit_points,
int energy_points,int max_energy_points,int level, int melee_attack_damage,
int ranged_attack_damage, int armor_damage_reduction)
{
    std::cout << "Clap-TP " + this->name + "has been created" << std::endl;
    this->hit_points = hit_points;
    this->max_hit_points = max_hit_points;
    this->energy_points = energy_points;
    this->max_energy_points = max_energy_points;
    this->level = 1;
    this->name = name;
    this->melee_attack_damage = melee_attack_damage;
    this->ranged_attack_damage = ranged_attack_damage;
    this->armor_damage_reduction = armor_damage_reduction;
}


ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Clap-TP " + this->name + "has been created" << std::endl;
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

ClapTrap::ClapTrap()
{
    std::cout << "a Clap-TP has been created" << std::endl;
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

ClapTrap::~ClapTrap()
{
    std::cout << "Clap-TP " + this->name + "has gone" << std::endl;
}

void    ClapTrap::rangedAttack(std::string const & target)
{
    std::cout << "Clap-TP " + this->name + " attacks " + target + " at range, causing ";
    std::cout << this->ranged_attack_damage;
    std::cout << " points of damage !" << std::endl;
}
void    ClapTrap::meleeAttack(std::string const & target)
{
    std::cout << "Clap-TP " + this->name + " attacks " + target + " with melee, causing ";
    std::cout << this->melee_attack_damage;
    std::cout << " points of damage !" << std::endl;
}
void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "Clap-TP " + this->name + " get damaged by an amount of " << std::endl;
    amount = amount - this->armor_damage_reduction;
   // if (amount <= 0)
    std::cout << amount;
    this->hit_points -= amount;
    if (this->hit_points <= 0)
        this->hit_points = 0;
}
void    ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "Clap-TP " + this->name + " being repared by an amount if" << std::endl;
    std::cout << amount;
    this->hit_points += amount;
    if (this->hit_points >= this->max_hit_points)
        this->hit_points = this->max_hit_points;
}
