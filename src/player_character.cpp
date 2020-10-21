#include "player_character.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <SFML/Window/Keyboard.hpp>

void PlayerCharacter::Init()
{
    if(!idleTexture_.loadFromFile("data/sprites/hero/still/hero1.png"))
    {
        std::cerr << "Could not load hero idle texture!\n";
    }
    sprite_.setTexture(idleTexture_);
    const auto textureSize = idleTexture_.getSize();
    sprite_.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite_.setPosition(100.0f, 100.0f);
    sprite_.setScale(3.0f, 3.0f);
}

void PlayerCharacter::Update(float dt)
{
    float dx = 0.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        dx -= 1.0f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        dx += 1.0f;
    }

    auto position = sprite_.getPosition();
    position.x += dx * speed_ * dt;
    sprite_.setPosition(position);


}

void PlayerCharacter::Render(sf::RenderWindow& window)
{
    window.draw(sprite_);
}

sf::Vector2<float> PlayerCharacter::GetPosition() const
{
    return sprite_.getPosition();
}
