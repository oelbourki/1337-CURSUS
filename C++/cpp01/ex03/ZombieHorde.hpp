
#include <iostream>
#include "Zombie.hpp"
class ZombieHorde
{
    private:
        int N;
        Zombie *user;
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
        std::string type;
    public:
        ZombieHorde(int N);
        ZombieHorde();
        ~ZombieHorde();
        void    create(int N);
        void randomChump(Zombie *user);
        void    announce();
        void    setZombieType(std::string type);
};