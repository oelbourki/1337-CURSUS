#include <iostream>

class Zombie
{
    private:
        std::string name;
        std::string type;
    public:
        void announce();
        Zombie(std::string name,std::string type);
        void    set_Zombie(std::string name,std::string type);
        Zombie();
        ~Zombie();
};