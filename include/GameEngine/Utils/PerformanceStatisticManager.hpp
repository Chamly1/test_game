#ifndef TEST_GAME_PERFORMANCESTATISTICMANAGER_HPP
#define TEST_GAME_PERFORMANCESTATISTICMANAGER_HPP

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

/**
 * Class for drawing base performance statistics, such as: FPS, logic update per second, simulation speed(in game
 * time flow), logic update time and render time.
 */
class PerformanceStatisticManager : public sf::Drawable {
private:
    sf::Font mStatisticFont;
    sf::Text mStatisticText;
    sf::RectangleShape mStatisticTextBackground;

    float mTargetLogicUpdatesPerSecond;
    float mLogicUpdatesPerSecond;

    float mStatisticsUpdateTime;
    int mFramesCounter;
    int mLogicUpdatesCounter;
    float mLogicUpdateTimeAccumulator;
    float mRenderTimeAccumulator;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

public:
    /**
     * Construct PerformanceStatisticManager.
     *
     * @param targetLogicUpdatesPerSecond logic updates per second that we set up for game.
     */
    explicit PerformanceStatisticManager(float targetLogicUpdatesPerSecond);
    /**
     * Update statistics. Update happen one time per second.
     *
     * @param dt delta time.
     */
    void update(double dt);
    /**
     * Increment frame counter which use to calculate FPS and render time. Call it once per every general render call.
     */
    void incrementFramesCounter();
    /**
     * Increment frame counter which use to calculate logic update per second, simulation speed and logic update time.
     * Call it once per every general update call.
     */
    void incrementLogicUpdatesCounter();
    /**
     * Accumulate render time which use to calculate render time. Call it for every general render call.
     *
     * @param time time that general render call take.
     */
    void accumulateRenderTime(float time);
    /**
     * Accumulate logic update time which use to calculate update time. Call it for every general update call.
     *
     * @param time time that general update call take.
     */
    void accumulateUpdateTime(float time);

};

#endif //TEST_GAME_PERFORMANCESTATISTICMANAGER_HPP
