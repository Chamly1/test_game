#include "GameEngine/Utils/PerformanceStatisticManager.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

#include <iostream>

#ifndef NDEBUG
static const sf::Vector2f STATISTIC_OVERLAY_POSITION(9.f, 475.f);
#else
static const sf::Vector2f STATISTIC_OVERLAY_POSITION(5.f, 5.f);
#endif
static const sf::Vector2f STATISTIC_OVERLAY_BACKGROUND_POSITION(STATISTIC_OVERLAY_POSITION + sf::Vector2f(0.f, 4.f));

static const unsigned int CHARACTER_SIZE = 15;
static const sf::Color TEXT_COLOR(0, 0, 0);
static const sf::Color BACKGROUND_COLOR(255, 255, 255);

void PerformanceStatisticManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mStatisticTextBackground, states);
    target.draw(mStatisticText, states);
}

PerformanceStatisticManager::PerformanceStatisticManager(float targetLogicUpdatesPerSecond)
: mStatisticFont()
, mStatisticText()
, mStatisticTextBackground()
, mTargetLogicUpdatesPerSecond(targetLogicUpdatesPerSecond)
, mStatisticsUpdateTime(0.f)
, mFramesCounter(0)
, mLogicUpdatesCounter(0)
, mLogicUpdateTimeAccumulator(0.f)
, mRenderTimeAccumulator(0.f) {

    if (!mStatisticFont.loadFromFile("resources/fonts/CONSOLA.TTF"))
    {
        std::cout << __FILE__ << ":" << __LINE__ << " font loading error!\n";
    }

    mStatisticText.setFont(mStatisticFont);
    mStatisticText.setPosition(STATISTIC_OVERLAY_POSITION);
    mStatisticText.setCharacterSize(CHARACTER_SIZE);
    mStatisticText.setFillColor(TEXT_COLOR);
    mStatisticText.setString("frames per second: -\nlogic updates per second: -\nsimulation speed: -x\nlogic update time: - s\nrender time: - s");

    mStatisticTextBackground.setPosition(STATISTIC_OVERLAY_BACKGROUND_POSITION);
    mStatisticTextBackground.setFillColor(BACKGROUND_COLOR);
    mStatisticTextBackground.setSize(sf::Vector2f(mStatisticText.getGlobalBounds().width, mStatisticText.getGlobalBounds().height));
}

void PerformanceStatisticManager::update(double dt) {
    mStatisticsUpdateTime += dt;

    if (mStatisticsUpdateTime >= 1.f) {
        mLogicUpdatesPerSecond = mLogicUpdatesCounter / mStatisticsUpdateTime;
        mStatisticText.setString("frames per second: " + std::to_string( mFramesCounter / mStatisticsUpdateTime) +
                                 "\nlogic updates per second: " + std::to_string(mLogicUpdatesPerSecond) +
                                 "\nsimulation speed: " + std::to_string(mLogicUpdatesPerSecond / mTargetLogicUpdatesPerSecond) + "x" +
                                 "\nlogic update time: " + std::to_string(mLogicUpdateTimeAccumulator / mLogicUpdatesCounter) + " s"
                                 "\nrender time: " + std::to_string(mRenderTimeAccumulator / mFramesCounter) + " s");
        mStatisticTextBackground.setSize(sf::Vector2f(mStatisticText.getGlobalBounds().width, mStatisticText.getGlobalBounds().height));

        mStatisticsUpdateTime = 0.f;
        mFramesCounter = 0;
        mLogicUpdatesCounter = 0;
        mLogicUpdateTimeAccumulator = 0.f;
        mRenderTimeAccumulator = 0.f;
    }
}

void PerformanceStatisticManager::incrementFramesCounter() {
    ++mFramesCounter;
}

void PerformanceStatisticManager::incrementLogicUpdatesCounter() {
    ++mLogicUpdatesCounter;
}

void PerformanceStatisticManager::accumulateRenderTime(float time) {
    mRenderTimeAccumulator += time;
}

void PerformanceStatisticManager::accumulateUpdateTime(float time) {
    mLogicUpdateTimeAccumulator += time;
}
