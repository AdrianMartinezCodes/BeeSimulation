#include <iostream>

class Bee{
    private:
        char representation = 'B';
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
        int x_cord;
        int y_cord;
        Bee();
        Bee(int x, int y);

    friend auto operator <<(std::ostream& os, Bee const& m) -> std::ostream& { 
        return os << m.representation;
    }
};