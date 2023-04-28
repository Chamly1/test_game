#ifndef TEST_GAME_LABEL_H
#define TEST_GAME_LABEL_H

#include "GameEngine/GUI/Component.h"

#include "SFML/Graphics/Text.hpp"

namespace GUI {

class Label : public Component {
private:
    sf::Text text;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Label(const std::string& text, const sf::Font& font);
    virtual bool isSelectable() const;
    virtual void handleEvent(const sf::Event& event);
    void setCharacterSize(unsigned int size);

};

}

#endif //TEST_GAME_LABEL_H
