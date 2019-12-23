#include <iostream>


class Brain
{
    private:
        Brain *einstein;
        int weight;
        int fats;
        int iq;
    public:
        Brain(int weight,int fats,int iq);
        Brain();
        ~Brain();
        std::string    identify() const;
};