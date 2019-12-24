#include "PowerFist.hpp"


PowerFist::PowerFist(PowerFist const &a)
{
    this->name = a.getName();
    this->ap = a.getAPCost();
    this->damage = a.getDamage();
}
PowerFist::PowerFist()
{
    this->name = "Power Fist";
    this->ap = 50;
    this->damage = 8;
}
PowerFist::~PowerFist()
{

}
PowerFist::PowerFist(std::string const & name, int apcost, int damage)
{
    this->name = name;
    this->ap = apcost;
    this->damage = damage;
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
