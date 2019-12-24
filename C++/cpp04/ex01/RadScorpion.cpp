#include "RadScorpion.hpp"

RadScorpion::RadScorpion(int hp, std::string const & type)
{
    std::cout << "* click click click *" << std::endl;
    this->hp = hp;
    this->type = type;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}
RadScorpion::RadScorpion()
{
    std::cout << "* click click click *" << std::endl;
    this->hp = 80;
    this->type = "RadScorpion";
}

void RadScorpion::takeDamage(int)
{
    if (!(this->hp - 25 <= 0))
    {
        this->hp -= 25;
    }
    else 
        this->hp = 0;
}