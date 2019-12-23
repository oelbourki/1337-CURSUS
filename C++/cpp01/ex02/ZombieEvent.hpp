#include <iostream>
#include "Zombie.hpp"

class ZombieEvent
{
    private:
        std::string type;
        std::string names[20] =
        {
            "Gus",
            "Harrison",
            "Sid",
            "Gerry",
            "Mariano",
            "Gayle",
            "Jay",
            "Deangelo",
            "Carmelo",
            "Hector",
            "Willian",
            "Gavin",
            "Rey",
            "Jessie",
            "Elwood",
            "Buford",
            "Jamar",
            "Kim",
            "Rogelio",
            "Alec",
        };
    public:
        void    setZombieType(std::string type);
        Zombie* newZombie(std::string name);
        Zombie* randomChump();
};