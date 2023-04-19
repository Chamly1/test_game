#include "GUI/Component.h"

namespace GUI {

Component::Component()
: mIsSelected(false)
, mIsActive(false) {

}

bool Component::isSelected() const {
    return mIsSelected;
}

void Component::select() {
    mIsSelected = true;
}

void Component::deselect() {
    mIsSelected = false;
}

bool Component::isActive() const {
    return mIsActive;
}

bool Component::activate() {
    mIsActive = true;
}

bool Component::deactivate() {
    mIsActive = false;
}

}