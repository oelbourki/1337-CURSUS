#pragma once
#include "Enemy.hpp"
class SuperMutant : public Enemy
{
    public:
        SuperMutant();
        void takeDamage(int);
        SuperMutant::SuperMutant(int hp, std::string const & type);
};

