#include "View.h"
#include <iostream>
View::View(unsigned int rows, unsigned int cols, float cellSize, sf::Texture& texture)
    : rows(rows), cols(cols), cellSize(cellSize), spriteSheet(texture, 11, 12) {
    for (unsigned int i = 0; i < rows; ++i) {
        std::vector<sf::Sprite> rowSprites;
        for (unsigned int j = 0; j < cols; ++j) {
            sf::Sprite cellSprite;
            cellSprite.setPosition(j * cellSize, i * cellSize);
            //std::cout << "cellsprite position set: " << j * cellSize << " " << i * cellSize << std::endl;
            rowSprites.push_back(cellSprite);
        }
        grid.push_back(rowSprites);
    }
}

void View::draw(sf::RenderWindow& window) {
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            //spriteSheet.set(rows, cols); // Set the sprite from the sprite sheet based on cell state
            spriteSheet.setPosition(cellSize * j, cellSize * i);
            window.draw(spriteSheet);
            debugGrid();
        }
    }
}


void View::setTextureForCell(unsigned int row, unsigned int col, int textureId) {
    if (textureId < 0 || textureId >= 12 * 11) {
        return;
    }

    int spriteRow = 0, spriteCol = 0;

    switch (textureId) {
        case 0: // Clicked cell (value 0)
            spriteRow = 0;
            spriteCol = 1;
            break;
        case 1: // Number 1
            spriteRow = 1;
            spriteCol = 0;
            break;
        case 2: // Number 2
            spriteRow = 1;
            spriteCol = 1;
            break;
        case 3: // Number 3
            spriteRow = 1;
            spriteCol = 2;
            break;
        case 4: // Number 4
            spriteRow = 1;
            spriteCol = 3;
            break;
        case 5: // Number 5
            spriteRow = 1;
            spriteCol = 4;
            break;
        case 6: // Number 6
            spriteRow = 1;
            spriteCol = 5;
            break;
        case 7: // Number 7
            spriteRow = 1;
            spriteCol = 6;
            break;
        case 8: // Number 8
            spriteRow = 1;
            spriteCol = 7;
            break;
        case 9: // Flag
            spriteRow = 0;
            spriteCol = 5;
            break;
        case 10: // bomba
            spriteRow = 0;
            spriteCol = 6;
            break;
        case 11: // Unclicked cell
            spriteRow = 0;
            spriteCol = 0;
            break;
        default:
            std::cout << "Texture ID not in range (0-11)." << std::endl;
            return;
    }

    std::cout << "Setting texture for cell (" << row << ", " << col << ") to textureId: " << textureId << std::endl;
    grid[row][col].setTextureRect(spriteSheet.getTextureRect(spriteRow, spriteCol));

}

void View::debugGrid() {
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            const sf::Sprite& sprite = grid[i][j];

            // Print position of the sprite
            sf::Vector2f position = sprite.getPosition();
            std::cout << "Grid[" << i << "][" << j << "] Position: ("
                      << position.x << ", " << position.y << ")" << std::endl;

            // Print the texture rectangle of the sprite
            sf::IntRect rect = sprite.getTextureRect();
            std::cout << "Grid[" << i << "][" << j << "] Texture Rect: ("
                      << rect.left << ", " << rect.top << ", "
                      << rect.width << ", " << rect.height << ")" << std::endl;
        }
    }
}
