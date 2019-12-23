#include <iostream>
#include <fstream>


void    replace_line(std::string &holder, std::string s1, std::string s2)
{
    std::size_t len = s1.length();
    std::size_t len_line = holder.length();
    std::size_t found;
     while (found < len_line - 1)
    {
        found = holder.find(s1, found);
        if (found > len_line)
            break;
        //std::cout << found << std::endl;
         holder.replace(found,len,s2);
         found++;
    }
    std::cout << holder << std::endl;
}
 void    replace_file(std::string filename, std::string s1, std::string s2)
 {
     std::ofstream file;
    std::ifstream from_file;
    std::ifstream from_file1;
    std::string holder;
    std::size_t found;
    std::size_t len = s1.length();
   from_file.open(filename,std::ios_base::in);
   file.open("text.replace",std::ios_base::out);
   from_file1.open(filename,std::ios_base::in);
    if(!file.is_open() || !from_file.is_open())
        return;
    while (from_file.good())
    {
        found = 0;
        // std::cout << "looping" << std::endl;
        getline(from_file, holder);
        
        std::size_t len_line = holder.length();
        
        while (found < len_line - 1)
        {
            found = holder.find(s1, found);
        if (found > len_line - 1)
            break;
        //std::cout << found << std::endl;
         holder.replace(found,len,s2);
         found++;
     }
        file << holder;
        file << "\n";
    }
}

int main()
{
   replace_file("text.text", "play", "work");
    return (0);
}