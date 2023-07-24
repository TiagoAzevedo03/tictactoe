#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(600, 600), "Tic Tac Toe");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::MouseButtonPressed){
            	if (event.mouseButton.button == Mouse::Left or event.mouseButton.button == Mouse::Right){
            		shape.setFillColor(Color::Blue);
				}
			}
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
