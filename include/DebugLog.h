#ifndef TEST_GAME_DEBUGLOG_H
#define TEST_GAME_DEBUGLOG_H

#include <iostream>
#include <sstream>
#include <deque>

#include "SFML/Graphics.hpp"

class DebugLog {
private:
    static sf::RenderWindow *window;
    static sf::Font font;
    static sf::Text text;
    static sf::RectangleShape background;
    static std::deque<std::string> logText;

    /**
     * Add string to logText based on debug "terminal" size.
     *
     * @param str string without "\n"
     */
    static void addToLogText(std::string str);
    static std::string logTextToString();

public:
    static void init(sf::RenderWindow *windowToSet);
    static void log(const std::string& str);
    static void draw();
};

#endif //TEST_GAME_DEBUGLOG_H
