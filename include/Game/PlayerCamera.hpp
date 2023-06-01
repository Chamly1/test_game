#ifndef TEST_GAME_PLAYERCAMERA_HPP
#define TEST_GAME_PLAYERCAMERA_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"

#include "SFML/Graphics/View.hpp"
#include "SFML/System/Time.hpp"

/**
 * Class to control a view according to player actions.
 */
class PlayerCamera {
private:
    sf::View mView;
    SceneNode *mPlayer;

public:
    explicit PlayerCamera(const sf::View& view);
    void setPlayer(SceneNode *player);
    sf::View getView();
    /**
     * Set view center to (0, 0) coordinates.
     */
    void resetCenter();
    /**
     * Set view center to player position coordinates (if it is initialized).
     */
    void resetCenterToPlayer();
    /**
     * Update the view position.
     *
     * @param dt delta time.
     */
    void update(sf::Time dt);

};

#endif //TEST_GAME_PLAYERCAMERA_HPP
