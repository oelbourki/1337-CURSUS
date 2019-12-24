#pragma once
#include "Enemy.hpp"
#include "AWeapon.hpp"
class Character
{
    private:
        std::string name;
        AWeapon *wep;
    public:
        Character(std::string const & name);
        Character(Character const &a);
        Character();
        ~Character();
        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);
        std::string &getName() const;
};