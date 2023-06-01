#ifndef TEST_GAME_BUTTONLIST_HPP
#define TEST_GAME_BUTTONLIST_HPP

#include "GameEngine/GUI/Component.hpp"
#include "GameEngine/GUI/Container.hpp"

#include "SFML/Graphics/Font.hpp"

namespace GUI {
/**
 * Class to represent vertical list of buttons.
 */
class ButtonList : public Component {
private:
    Container mButtons;
    const sf::Font& mFont;
    const sf::Texture& mSelectorTexture;
    unsigned int mCharacterSize;
    int mButtonsCount;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    ButtonList(unsigned int characterSize, const sf::Font& font, const sf::Texture& selectorTexture);
    void addButton(const std::string& text, std::function<void()> callback);
    virtual bool isSelectable() const;
    virtual void handleEvent(const sf::Event& event);

};

}

#endif //TEST_GAME_BUTTONLIST_HPP
