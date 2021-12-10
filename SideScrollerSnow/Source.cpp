#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
    RenderWindow window(VideoMode(800, 800), "SFML works!");
    RectangleShape square;

    square.setSize(Vector2f(100.f, 100.f));
    square.setFillColor(Color::White);
    square.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(square);
        window.display();
    }

    return 0;
}