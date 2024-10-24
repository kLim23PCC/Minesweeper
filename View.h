//
// Created by klimz on 10/22/2024.
//

#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "SpriteSheetCutter.h"
class View {
public:
    View(unsigned int rows, unsigned int cols, float cellSize, sf::Texture& texture);
    void setTextureForCell(unsigned int row, unsigned int col, int value);
    void draw(sf::RenderWindow& window);
private:
    unsigned int rows, cols;
    float cellSize;
    sf::Texture textureSheet; // Holds the texture for all sprites
    SpriteSheetCutter spriteSheet;
    std::vector<std::vector<sf::Sprite>> grid; // Sprites for the grid
    void debugGrid();
};

#endif // VIEW_H
