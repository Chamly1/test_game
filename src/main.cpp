#include "iostream"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

int main()
{

    // Window setup
    sf::RenderWindow window(sf::VideoMode(800, 600), "test_game", sf::Style::Default);
    sf::Event ev;

    // Game loop
    while (window.isOpen()) {
        // Event polling
        while (window.pollEvent(ev)) {
            switch (ev.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
//                    std::cout << "key pressed" << std::endl;
//                    std::cout << ev.key.code << std::endl;
                    break;
            }
        }

        // Update

        // Render
        window.clear();
        window.display();
    }

    return 0;
}
