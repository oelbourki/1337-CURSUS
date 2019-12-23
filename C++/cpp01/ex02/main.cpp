#include <iostream>
#include "ZombieEvent.hpp"
#include "Zombie.hpp"




int     main()
{
    std::string type;
    ZombieEvent event;
    std::string name;
    Zombie *user;
    std::cout << "enter the type" << std::endl;
    std::cin >> type;
    event.setZombieType(type);
    std::cout <<"enter the name or 'random'" << std::endl;
    std::cin >> name;
    if (name == "random")
       user =  event.randomChump();
    else 
        user = event.newZombie(name);
    return (0);
}