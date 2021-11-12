class Bee{
    private:
        char x_cord;
        char y_cord;
        
        enum class worker_type {
        clean,
        feedOne,
        feedTwo,
        recieve,
        beeswax,
        field,
        death
        };
    
    public: 

        Bee(char x, char y);
        void add_to_map(char x, char y);


};