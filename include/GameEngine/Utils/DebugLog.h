#ifndef TEST_GAME_DEBUGLOG_H
#define TEST_GAME_DEBUGLOG_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

#include <deque>

#ifndef NDEBUG

#define DEBUG_INIT(window) \
    DebugLog::init(window); \

#define DEBUG_LOG(str) \
    DebugLog::log(str); \

#define DEBUG_DRAW() \
    DebugLog::draw(); \

#else

#define DEBUG_INIT(window)

#define DEBUG_LOG(str)

#define DEBUG_DRAW()

#endif

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
