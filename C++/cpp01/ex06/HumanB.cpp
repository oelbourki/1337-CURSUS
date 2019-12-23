#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}
HumanB::HumanB()
{
    this->name = "";
    this->tool = NULL;
}
HumanB::~HumanB()
{
}
void    HumanB::attack()
{
    std::cout << this->name + " attacks with his " + this->tool->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &tool)
{
    this->tool = &tool;
}