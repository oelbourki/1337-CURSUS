#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"



class HumanB
{
    private:
        std::string name;
        Weapon *tool;
    public:
        HumanB(std::string name);
        HumanB();
        ~HumanB();
        void    attack();
        void    setWeapon(Weapon &tool);
};
#endif