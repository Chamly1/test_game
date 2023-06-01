#include "Game/PlayerCamera.hpp"

// an area in the center of the view where the center of the view doesn't change position because of player position change
static const sf::Vector2f noMoveAreaSize(16.f * 30, 9.f * 30);

PlayerCamera::PlayerCamera(const sf::View& view)
: view(view)
, player(nullptr) {

}

void PlayerCamera::setPlayer(SceneNode *player) {
    this->player = player;
}

sf::View PlayerCamera::getView() {
    return view;
}

void PlayerCamera::resetCenter() {
    view.setCenter(0.f, 0.f);
}

void PlayerCamera::resetCenterToPlayer() {
    if (!player) {
        return;
    }
    view.setCenter(player->getWorldPosition());
}

static float calcCameraMoveDelta(float relativePlayerCoordinate, float halfNoMoveSize) {
    if (relativePlayerCoordinate >= 0.f) {
        if (relativePlayerCoordinate > halfNoMoveSize) {
            return relativePlayerCoordinate - halfNoMoveSize;
        }
    } else {
        if (relativePlayerCoordinate < -halfNoMoveSize) {
            return relativePlayerCoordinate + halfNoMoveSize;
        }
    }
    return 0.f;
}

void PlayerCamera::update(sf::Time dt) {
    if (!player) {
        return;
    }

    sf::Vector2f viewCenter = view.getCenter();
    // player position relatively to the viewCenter
    sf::Vector2f RelativePlayerPos;

    RelativePlayerPos = player->getWorldPosition() - viewCenter;

    viewCenter.x += calcCameraMoveDelta(RelativePlayerPos.x, noMoveAreaSize.x / 2.f);
    viewCenter.y += calcCameraMoveDelta(RelativePlayerPos.y, noMoveAreaSize.y / 2.f);

    view.setCenter(viewCenter);
}
