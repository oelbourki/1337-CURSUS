#include "AWeapon.hpp"


AWeapon::AWeapon(AWeapon const &a)
{
    this->name = a.getName();
    this->ap = a.getAPCost();
    this->damage = a.getDamage();
}

AWeapon &AWeapon::operator=(AWeapon const &a)
{
    this->name = a.getName();
    this->ap = a.getAPCost();
    this->damage = a.getDamage();
    return *this;
}
AWeapon::AWeapon()
{
    this->name = "";
    this->ap = 0;
    this->damage = 0;
}
AWeapon::~AWeapon()
{

}
AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
    this->name = name;
    this->ap = apcost;
    this->damage = damage;
}
std::string AWeapon::getName() const
{
    return this->name;
}
int AWeapon::getAPCost() const
{
    return this->ap;
}
int AWeapon::getDamage() const
{
    return this->damage;
}
void AWeapon::attack() const
{
    std::cout << "idealist" << std::endl;
}
