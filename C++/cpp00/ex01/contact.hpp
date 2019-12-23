
class contact
{
    private:
        std::string table[11];
        static int numofuser;
    public:
        contact(std::string *table);
        void    print_table();
        void    set(std::string *table);
        contact();
        void    search(int j);
};