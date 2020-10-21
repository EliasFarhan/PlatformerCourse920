#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace sf
{
    class RenderWindow;
}

class PlayerCharacter
{
public:
    void Init();
    /**
     * \brief Player takes inputs and modify sprites
     * (it does not render the sprite)
     */
    void Update(float dt);
    void Render(sf::RenderWindow& window);
    sf::Vector2<float> GetPosition() const;
private:
    sf::Texture idleTexture_;
    sf::Sprite sprite_;
    const float speed_ = 100.0f; //frame per second
};
