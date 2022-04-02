#include <SFML/Graphics.hpp>
//alguma coisa
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    //quinta pilha
    sf::RectangleShape line53(sf::Vector2f(1.f, 220.f));
    line53.setPosition(500.f,530.f);
    sf::RectangleShape line52(sf::Vector2f(52.f, 1.f));
    line52.setPosition(449.f,750.f);
    sf::RectangleShape line51(sf::Vector2f(1.f, 220.f));
    line51.setPosition(449.f,530.f);

    sf::RectangleShape shape54(sf::Vector2f(50.f, 50.f));
    shape54.setFillColor(sf::Color::Black );
    shape54.setPosition(450.f,550.f);

    sf::RectangleShape shape53(sf::Vector2f(50.f, 50.f));
    shape53.setFillColor(sf::Color::Black);
    shape53.setPosition(450.f,600.f);

    sf::RectangleShape shape52(sf::Vector2f(50.f, 50.f));
    shape52.setFillColor(sf::Color::Black);
    shape52.setPosition(450.f,650.f);

    sf::RectangleShape shape51(sf::Vector2f(50.f, 50.f));
    shape51.setFillColor(sf::Color::Black);
    shape51.setPosition(450.f,700.f);

    //quarta pilha
    sf::RectangleShape line43(sf::Vector2f(1.f, 220.f));
    line43.setPosition(400.f,530.f);
    sf::RectangleShape line42(sf::Vector2f(52.f, 1.f));
    line42.setPosition(349.f,750.f);
    sf::RectangleShape line41(sf::Vector2f(1.f, 220.f));
    line41.setPosition(349.f,530.f);

    sf::RectangleShape shape44(sf::Vector2f(50.f, 50.f));
    shape44.setFillColor(sf::Color::Black );
    shape44.setPosition(350.f,550.f);

    sf::RectangleShape shape43(sf::Vector2f(50.f, 50.f));
    shape43.setFillColor(sf::Color::Black);
    shape43.setPosition(350.f,600.f);

    sf::RectangleShape shape42(sf::Vector2f(50.f, 50.f));
    shape42.setFillColor(sf::Color::Black);
    shape42.setPosition(350.f,650.f);

    sf::RectangleShape shape41(sf::Vector2f(50.f, 50.f));
    shape41.setFillColor(sf::Color::Black);
    shape41.setPosition(350.f,700.f);

    //terceira pilha
    sf::RectangleShape line33(sf::Vector2f(1.f, 220.f));
    line33.setPosition(300.f,530.f);
    sf::RectangleShape line32(sf::Vector2f(52.f, 1.f));
    line32.setPosition(249.f,750.f);
    sf::RectangleShape line31(sf::Vector2f(1.f, 220.f));
    line31.setPosition(249.f,530.f);

    sf::RectangleShape shape34(sf::Vector2f(50.f, 50.f));
    shape34.setFillColor(sf::Color(102, 204, 255) );
    shape34.setPosition(250.f,550.f);

    sf::RectangleShape shape33(sf::Vector2f(50.f, 50.f));
    shape33.setFillColor(sf::Color(255, 204, 255));
    shape33.setPosition(250.f,600.f);

    sf::RectangleShape shape32(sf::Vector2f(50.f, 50.f));
    shape32.setFillColor(sf::Color(255, 102, 102));
    shape32.setPosition(250.f,650.f);

    sf::RectangleShape shape31(sf::Vector2f(50.f, 50.f));
    shape31.setFillColor(sf::Color(102, 204, 255) );
    shape31.setPosition(250.f,700.f);

    //segunda pilha
    sf::RectangleShape line23(sf::Vector2f(1.f, 220.f));
    line23.setPosition(200.f,530.f);
    sf::RectangleShape line22(sf::Vector2f(52.f, 1.f));
    line22.setPosition(149.f,750.f);
    sf::RectangleShape line21(sf::Vector2f(1.f, 220.f));
    line21.setPosition(149.f,530.f);

    sf::RectangleShape shape24(sf::Vector2f(50.f, 50.f));
    shape24.setFillColor(sf::Color(255, 102, 102));
    shape24.setPosition(150.f,550.f);

    sf::RectangleShape shape23(sf::Vector2f(50.f, 50.f));
    shape23.setFillColor(sf::Color(102, 204, 255) );
    shape23.setPosition(150.f,600.f);

    sf::RectangleShape shape22(sf::Vector2f(50.f, 50.f));
    shape22.setFillColor(sf::Color(255, 204, 255));
    shape22.setPosition(150.f,650.f);


    sf::RectangleShape shape21(sf::Vector2f(50.f, 50.f));
    shape21.setFillColor(sf::Color(255, 204, 255));
    shape21.setPosition(150.f,700.f);

    //primeira pilha
    sf::RectangleShape line13(sf::Vector2f(1.f, 220.f));
    line13.setPosition(100.f,530.f);
    sf::RectangleShape line12(sf::Vector2f(52.f, 1.f));
    line12.setPosition(49.f,750.f);
    sf::RectangleShape line11(sf::Vector2f(1.f, 220.f));
    line11.setPosition(49.f,530.f);

    sf::RectangleShape shape14(sf::Vector2f(50.f, 50.f));
    shape14.setFillColor(sf::Color(255, 102, 102));
    shape14.setPosition(50.f,550.f);

    sf::RectangleShape shape13(sf::Vector2f(50.f, 50.f));
    shape13.setFillColor(sf::Color(102, 204, 255) );
    shape13.setPosition(50.f,600.f);

    sf::RectangleShape shape12(sf::Vector2f(50.f, 50.f));
    shape12.setFillColor(sf::Color(255, 204, 255));
    shape12.setPosition(50.f,650.f);


    sf::RectangleShape shape11(sf::Vector2f(50.f, 50.f));
    shape11.setFillColor(sf::Color(255, 102, 102));
    shape11.setPosition(50.f,700.f);

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //primeira pilha
        window.draw(line11);
        window.draw(line12);
        window.draw(line13);

        window.draw(shape11);
        window.draw(shape12);
        window.draw(shape13);
        window.draw(shape14);

        //segunda pilha
        window.draw(line21);
        window.draw(line22);
        window.draw(line23);

        window.draw(shape21);
        window.draw(shape22);
        window.draw(shape23);
        window.draw(shape24);

        //terceira pilha
        window.draw(line31);
        window.draw(line32);
        window.draw(line33);

        window.draw(shape31);
        window.draw(shape32);
        window.draw(shape33);
        window.draw(shape34);

        //quarta pilha
        window.draw(line41);
        window.draw(line42);
        window.draw(line43);

        window.draw(shape41);
        window.draw(shape42);
        window.draw(shape43);
        window.draw(shape44);

        //quinta pilha
        window.draw(line51);
        window.draw(line52);
        window.draw(line53);

        window.draw(shape51);
        window.draw(shape52);
        window.draw(shape53);
        window.draw(shape54);

        window.display();
    }

    return 0;
}