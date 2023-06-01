#ifndef TEST_GAME_BUTTON_HPP
#define TEST_GAME_BUTTON_HPP

#include "GameEngine/GUI/Component.hpp"

#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Sprite.hpp"

#include <functional>

namespace GUI {

class Button : public Component {
private:
    std::function<void()> callback;
    sf::Text text;
    sf::Sprite selector;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void correctSelector();

public:
    Button(const std::string& text, const sf::Font& font, const sf::Texture& selectorTexture);
    void setCallback(std::function<void()> callback);
    virtual bool isSelectable() const;
    virtual void activate();
    virtual void handleEvent(const sf::Event& event);
    void setCharacterSize(unsigned int size);

};

}

#endif //TEST_GAME_BUTTON_HPP
