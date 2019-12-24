#include "Enemy.hpp"


Enemy::Enemy(int hp, std::string const & type)
{
    this->hp = hp;
    this->type = type;
}
Enemy::Enemy()
{
    this->hp = 50;
    this->type = "mokahla";
}
Enemy::~Enemy()
{

}
Enemy::Enemy(Enemy const &a)
{
    this->hp = hp;
    this->type = type;
}
Enemy &Enemy::operator=(Enemy const &a)
{
    this->hp = hp;
    this->type = type;
    return *this;
}


std::string Enemy::getType() const
{
    return this->type;
}
int Enemy::getHP() const
{
    return this->hp;
}
void Enemy::takeDamage(int)
{
    if (!(this->hp - 21 <= 0))
    {
        this->hp -= 21;
    }
    else 
        this->hp = 0;

}