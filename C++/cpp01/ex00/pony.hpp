#include <iostream>

class Pony
{
    private:
        std::string color;
        std::string name;
        std::string clane;
        int height;
        int weight;
    public:
        Pony(std::string color, std::string name, std::string clane, int height, int weight);
        void    set(std::string color, std::string name, std::string clane, int height, int weight);
        Pony();
       // ~Pony();
        void    print_song();
};