//
// Created by klimz on 10/22/2024.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Model.h"
#include "View.h"

class Controller {
public:
    Controller(Model& model, View& view, float cellSize);
    void handleLeftClick(const sf::Vector2i& mousePos);
    void handleRightClick(const sf::Vector2i& mousePos);
    void revealCell(int row, int col);
    void updateView();
    void revealBoard();
private:
    Model& model;
    View& view;
    float cellSize;
    bool firstClick;
};


#endif //CONTROLLER_H
