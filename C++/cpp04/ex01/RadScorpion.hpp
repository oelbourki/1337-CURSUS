#pragma once
#include "Enemy.hpp"
class RadScorpion : public Enemy
{
    public:
        RadScorpion();
        void takeDamage(int);
        RadScorpion::RadScorpion(int hp, std::string const & type);
};

