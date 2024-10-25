#include "Paddle.h"
#include <iostream>

Paddle::Paddle(sf::RenderWindow* window)
    : _window(window), _width(PADDLE_WIDTH), _timeInNewSize(0.0f), _isAlive(true)
{
    _sprite.setFillColor(sf::Color::Cyan);
    _sprite.setPosition((window->getSize().x - _width) / 2.0f, window->getSize().y - 100.0f);
    _sprite.setSize(sf::Vector2f(_width, PADDLE_HEIGHT));
    _sprite.setOrigin(sf::Vector2f(_width/2, PADDLE_HEIGHT/2));
}

Paddle::~Paddle()
{
}

void Paddle::moveLeft(float dt)
{
    float position = _sprite.getPosition().x;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position > 0)
    {
        _sprite.move(sf::Vector2f(-dt * PADDLE_SPEED, 0));
    }
}

void Paddle::moveRight(float dt)
{
    float position = _sprite.getPosition().x;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && position < _window->getSize().x - _width)
    {
        _sprite.move(sf::Vector2f(dt * PADDLE_SPEED, 0));
    }
}

void Paddle::mouseMove(float dt, sf::RenderWindow* window) {
   
    _sprite.setPosition(sf::Vector2f(sf::Mouse::getPosition().x , _sprite.getPosition().y));
  
}

void Paddle::colourChange() {


    switch (rand() % 6)
    {
    case 0:
        _sprite.setFillColor(sf::Color::Cyan);
        break;
    case 1:
        _sprite.setFillColor(sf::Color::Blue);
        break;
    case 2:
        _sprite.setFillColor(sf::Color::Green);
        break;
    case 3:
        _sprite.setFillColor(sf::Color::Magenta);
        break;
    case 4:
        _sprite.setFillColor(sf::Color::White);
        break;
    case 5:
        _sprite.setFillColor(sf::Color::Yellow);
        break;
    default:
        break;
    }

}

void Paddle::turnPaddle(float dir) {

    _sprite.setRotation(45*dir);

}

float  Paddle::getPaddleDir() {

    if (_sprite.getRotation() == 0) { return -1; }
   
    return _sprite.getRotation();

}

void Paddle::update(float dt)
{
    if (_timeInNewSize > 0)
    {
        _timeInNewSize -= dt;
    }
    else
    {
        setWidth(1.0f, 0.0f); // Reset to default width after duration
    }
}

void Paddle::render()
{
    _window->draw(_sprite);
}

sf::FloatRect Paddle::getBounds() const
{
    return _sprite.getGlobalBounds();
}

// update width by SF of coeff. 
// ensure centre remains consistent.
void Paddle::setWidth(float coeff, float duration)
{
    _width = coeff * PADDLE_WIDTH;
    _sprite.setSize(sf::Vector2f(_width, _sprite.getSize().y));
    _timeInNewSize = duration;
    float newX = _sprite.getPosition().x + (_width - PADDLE_WIDTH) / 2;
    _sprite.setPosition(newX, _sprite.getPosition().y);
}
