#include "SuperMutant.hpp"

SuperMutant::SuperMutant(int hp, std::string const & type)
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    this->hp = hp;
    this->type = type;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh ..." << std::endl;
}
SuperMutant::SuperMutant()
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    this->hp = 170;
    this->type = "Super Mutant";
}

void SuperMutant::takeDamage(int)
{
    if (!(this->hp - 25 <= 0))
    {
        this->hp -= 25;
    }
    else 
        this->hp = 0;
}