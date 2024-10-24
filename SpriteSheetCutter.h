//
// Created by klimz on 10/14/2024.
//

#ifndef SPRITESHEETCUTTER_H
#define SPRITESHEETCUTTER_H

#include <SFML/Graphics.hpp>
#include <cmath>
class SpriteSheetCutter : public sf::Sprite{
private:
    sf::Texture &_texture;
    int _rows, _cols;
    sf::IntRect _int_rect;
    void setIntRectSize();
    void setupSprite();
public:
    SpriteSheetCutter();
    SpriteSheetCutter(sf::Texture &texture,int rows, int col);
    sf::IntRect getTextureRect(int row, int col);
    void set(int row, int col);
    void init();
};



#endif //SPRITESHEETCUTTER_H
