//
// Created by klimz on 10/23/2024.
//

#include "Minesweeper.h"
#include <iostream>

Minesweeper::Minesweeper(unsigned int screenWidth, unsigned int screenHeight, const std::string& title, Controller& controller, View& view)
    : window(sf::VideoMode(screenWidth, screenHeight), title), controller(controller), view(view) {}

void Minesweeper::run() {
    while (window.isOpen()) {
        handleInput();
        render();
    }
}

void Minesweeper::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                // Handle left click to reveal cell
                //std::cout << "Left button pressed" << std::endl;
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                controller.handleLeftClick(mousePos);
            }
            else if (event.mouseButton.button == sf::Mouse::Right) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                controller.handleRightClick(mousePos);
                // handle right click for flags
            }
        }

    }
}

void Minesweeper::render() {
    window.clear(sf::Color::Black); // Clear the window with black

    controller.revealBoard();
    view.draw(window);

    window.display(); // Display what has been rendered
}

