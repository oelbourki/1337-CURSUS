#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &tool)
{
    this->name = name;
    this->tool = &tool;
}
HumanA::HumanA()
{
    this->name = "";
    this->tool = NULL;
}
HumanA::~HumanA()
{
}
void    HumanA::attack()
{
    std::cout << this->name + " attacks with his " + this->tool->getType() << std::endl;
}
void    HumanA::setWeapon(Weapon &tool)
{
    this->tool = &tool;
}