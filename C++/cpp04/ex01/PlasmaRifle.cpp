#include "PlasmaRifle.hpp"


PlasmaRifle::PlasmaRifle(PlasmaRifle const &a)
{
    this->name = a.getName();
    this->ap = a.getAPCost();
    this->damage = a.getDamage();
}
PlasmaRifle::PlasmaRifle()
{
    this->name = "Plasma Rifle";
    this->ap = 21;
    this->damage = 5;
}
PlasmaRifle::~PlasmaRifle()
{

}
PlasmaRifle::PlasmaRifle(std::string const & name, int apcost, int damage)
{
    this->name = name;
    this->ap = apcost;
    this->damage = damage;
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
