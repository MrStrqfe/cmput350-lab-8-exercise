#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include "sprite.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>

using SpriteID = size_t;

class SpriteManager {
public:
    sf::Texture& registerTexture(const std::string& filepath) {
        // Initialized the texture if it is not inside hashMap
        if (!regTextures.contains(filepath)) {
            regTextures[filepath] = sf::Texture(filepath);
        }

        return regTextures[filepath];

    }

    template<typename... Args>
    SpriteID createSprite(Args&&... args) {
        // Constructs the Sprite directly inside the vector's memory
        sprites.emplace_back(std::forward<Args>(args)...);
        return sprites.size() - 1;
    }

    Sprite& getSprite(SpriteID id) {
        return sprites[id];
    }

private:
    std::unordered_map<std::string, sf::Texture> regTextures = {};
    std::vector<Sprite> sprites = {};
};

#endif  // SPRITE_MANAGER_H
