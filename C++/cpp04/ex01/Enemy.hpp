#pragma once
#include <iostream>

class Enemy 
{
    protected:
        int hp;
        std::string type;

    public:
        Enemy(int hp, std::string const & type);
        Enemy();
        ~Enemy();
        Enemy(Enemy const &a);
        Enemy &operator=(Enemy const &a);
        std::string getType() const;
        int getHP() const;
        virtual void takeDamage(int);
};