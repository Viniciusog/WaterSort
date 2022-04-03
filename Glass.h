#include <SFML/Graphics.hpp>
using namespace std;

class Glass {
    public:
        Glass();
        ~Glass();
        void setColor(int index, sf::Color color);
    private:
        sf::Color colors[4];
};