#include "Utils/DebugLog.h"

#include "iostream"
#include "sstream"

sf::RenderWindow *DebugLog::window;
sf::Font DebugLog::font;
sf::Text DebugLog::text;
sf::RectangleShape DebugLog::background;
std::deque<std::string> DebugLog::logText;

#define CHARACTER_SIZE 16
#define CHARACTER_WIDTH 9.f
#define CHARACTER_HEIGHT 19.f
#define CHARACTERS_COLUMNS_NUM 80
#define CHARACTERS_ROWS_NUM 24
#define BACKGROUND_COLOR sf::Color(255, 255, 255, 50)
#define BACKGROUND_OUTLINE_COLOR sf::Color(255, 255, 255, 100)
#define TEXT_COLOR sf::Color(255, 255, 255)

void DebugLog::init(sf::RenderWindow *windowToSet) {
    window = windowToSet;

    background.setPosition(CHARACTER_WIDTH, CHARACTER_HEIGHT);
    background.setSize(sf::Vector2f(CHARACTER_WIDTH * CHARACTERS_COLUMNS_NUM, CHARACTER_HEIGHT * CHARACTERS_ROWS_NUM));
    background.setFillColor(BACKGROUND_COLOR);
    background.setOutlineThickness(1.f);
    background.setOutlineColor(BACKGROUND_OUTLINE_COLOR);

    if (!font.loadFromFile("resources/fonts/CONSOLA.TTF"))
    {
        std::cout << __FILE__ << ":" << __LINE__ << " font loading error!\n";
    }
    text.setFont(font);
    text.setPosition(CHARACTER_WIDTH, CHARACTER_HEIGHT);
    text.setCharacterSize(CHARACTER_SIZE);
    text.setFillColor(TEXT_COLOR);
}

void DebugLog::addToLogText(std::string str) {
    int charsRemain = str.length();
    int index = 0;

    while (charsRemain > 0) {
        logText.push_back(str.substr(index, CHARACTERS_COLUMNS_NUM));
        charsRemain -= CHARACTERS_COLUMNS_NUM;
    }

    while (logText.size() > CHARACTERS_ROWS_NUM) {
        logText.pop_front();
    }
}

std::string DebugLog::logTextToString() {
    std::stringstream ss;
    for(auto it = logText.cbegin(); it != logText.cend(); it++)
    {
        ss << *it << "\n";
    }
    return ss.str();
}

void DebugLog::log(const std::string& str) {
    int index1 = 0;
    int index2 = 0;

    while (true) {
        index2 = str.find("\n", index1);
        if(index1 >= str.length()) {
            break;
        } else if (index2 == std::string::npos) {
            addToLogText(str.substr(index1, str.length() - index1));
            break;
        } else {
            addToLogText(str.substr(index1, index2 - index1));
            index1 = index2 + 1;
        }
    }

    text.setString(logTextToString());
}

void DebugLog::draw() {
    window->draw(background);
    window->draw(text);
}
