#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"



class HumanA
{
    private:
        std::string name;
        Weapon *tool;
    public:
        HumanA(std::string name, Weapon &tool);
        HumanA();
        ~HumanA();
        void    attack();
        void    setWeapon(Weapon &tool);
};

#endif