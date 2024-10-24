//
// Created by klimz on 10/14/2024.
//

#include "SpriteSheetCutter.h"


SpriteSheetCutter::SpriteSheetCutter(sf::Texture &texture, int rows, int cols)
    : _texture(texture), _rows(rows), _cols(cols)
{
    init();
}

void SpriteSheetCutter::set(int row, int col) {
    // make sure the row and col are valid
    _int_rect.top = _int_rect.height * row;
    _int_rect.left = _int_rect.width * col;
    setTextureRect(_int_rect);
}

void SpriteSheetCutter::init() {
    setIntRectSize();
    setupSprite();
}

void SpriteSheetCutter::setIntRectSize() { // get size of box within minesweeper cut sprite sheet.
    _int_rect.width  = std::round(_texture.getSize().x / _cols);
    _int_rect.height = std::round(_texture.getSize().y / _rows);
}

void SpriteSheetCutter::setupSprite() {
    sf::Sprite::setTexture(_texture);
    sf::Sprite::setTextureRect(_int_rect);
}

sf::IntRect SpriteSheetCutter::getTextureRect(int row, int col) {
    set(row, col);
    return _int_rect;
}
