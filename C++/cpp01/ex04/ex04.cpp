#include <iostream>


int     main()
{
    std::string brain;
    std::string *string_ptr;
    brain = "HI THIS IS BRAIN";
    std::string &string_ref(brain);
    string_ptr = &brain;
    std::cout << *string_ptr << std::endl;
    std::cout << string_ref << std::endl;
    return (0);
}