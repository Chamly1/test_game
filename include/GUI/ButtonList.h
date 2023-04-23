#ifndef TEST_GAME_BUTTONLIST_H
#define TEST_GAME_BUTTONLIST_H

#include "GUI/Component.h"
#include "GUI/Container.h"

#include "SFML/Graphics/Font.hpp"

namespace GUI {
/**
 * Class to represent vertical list of buttons.
 */
class ButtonList : public Component {
private:
    Container buttons;
    const sf::Font& font;
    const sf::Texture& selectorTexture;
    unsigned int characterSize;
    int buttonsCount;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    ButtonList(unsigned int characterSize, const sf::Font& font, const sf::Texture& selectorTexture);
    void addButton(const std::string& text, std::function<void()> callback);
    virtual bool isSelectable() const;
    virtual void handleEvent(const sf::Event& event);

};

}

#endif //TEST_GAME_BUTTONLIST_H