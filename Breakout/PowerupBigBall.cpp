#include "PowerupBigBall.h"

PowerupBigBall::PowerupBigBall(sf::RenderWindow* window, Paddle* paddle, Ball* ball)
    : PowerupBase(window, paddle, ball)
{
    _sprite.setFillColor(BallSizeEffectsColour);
}

PowerupBigBall::~PowerupBigBall()
{
}

std::pair<POWERUPS, float> PowerupBigBall::applyEffect()
{
    _ball->setSize(40);
    return { bigball, 5.0f };
}