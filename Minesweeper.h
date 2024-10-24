//
// Created by klimz on 10/23/2024.
//

#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <SFML/Graphics.hpp>
#include "View.h"
#include "Controller.h"

class Minesweeper {
public:
    Minesweeper(unsigned int screenWidth, unsigned int screenHeight, const std::string& title, Controller& controller, View& view);
    void run();
    void render();
    void handleInput();

private:
    sf::RenderWindow window;
    Controller& controller;
    View& view;
};

#endif // MINESWEEPER_H

