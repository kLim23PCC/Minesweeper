//
// Created by klimz on 10/22/2024.
//

#include "Controller.h"

#include <iostream>

Controller::Controller(Model& model, View& view, float cellSize)
    : model(model), view(view), cellSize(cellSize), firstClick(true) {}

void Controller::handleLeftClick(const sf::Vector2i& mousePos) {
    int col = mousePos.x / cellSize;
    int row = mousePos.y / cellSize;

    if (col >= 0 && col < model.getCols() && row >= 0 && row < model.getRows()) {
        if (firstClick) {
            int cellValue = model.getCellValue(row, col);
            //std::cout << "Clicked (" << col << ", " << row << ") Value: " << cellValue << std::endl;
            //model.setCellValue(row, col, 11); // Set all cells to unclicked (11)
            // Fill the grid with the unclicked cell texture
            /*
            for (unsigned int r = 0; r < model.getRows(); ++r) {
                for (unsigned int c = 0; c < model.getCols(); ++c) {
                    model.setCellValue(r, c, 11); // Set all cells to unclicked (11)
                    //view.setTextureForCell(r, c, 11); // Update the view with unclicked cells
                }
            }
            */
            // Initialize mines after first click, ensuring the clicked cell is safe
            model.initializeMines(row, col);
            firstClick = false;
        }

        if (model.isMine(row, col)) {
            view.setTextureForCell(row, col, 10); // Set texture for a clicked mine (10)
        } else {
            model.printGrid();
            revealBoard();
            //revealCell(row, col); // Custom function to reveal the clicked cell and adjacent cells
        }
    }
}


void Controller::handleRightClick(const sf::Vector2i &mousePos) {
    int col = mousePos.x / cellSize;
    int row = mousePos.y / cellSize;

    if (col >= 0 && col < model.getCols() && row >= 0 && row < model.getRows()) {
        model.setCellValue(row, col,9); // 9 is for flags

    }
}
/*
void Controller::revealCell(int row, int col) {
    std::cout << "reveal cell function called!" << std::endl;
    // Check if the cell is within bounds and not already revealed
    if (row < 0 || row >= model.getRows() || col < 0 || col >= model.getCols() || model.isCellRevealed(row, col)) {
        return;
    }

    int cellValue = model.getCellValue(row, col);

    // Set the texture
    view.setTextureForCell(row, col, cellValue); // Update the view with the cell value
    model.revealCell(row, col); // Mark the cell as revealed

    // If the cell is 0, reveal adjacent cells
    if (cellValue == 0) {
        for (int r = row - 1; r <= row + 1; ++r) {
            for (int c = col - 1; c <= col + 1; ++c) {
                if (!(r == row && c == col)) {
                    revealCell(r, c); // Reveal adjacent cells recursively
                }
            }
        }
    }
}
*/
void Controller::revealBoard() {
    for (unsigned int i = 0; i < model.getRows(); ++i) {
        for (unsigned int j = 0; j < model.getCols(); ++j) {
            int cellValue = model.getCellValue(i, j);
            //std::cout << "Cell (" << i << ", " << j << ") " << cellValue << std::endl;

            if (cellValue == 10) {
                view.setTextureForCell(i, j, 10);
                std::cout << "Bomb set :" << cellValue << std::endl;

            } else if (cellValue == 0) {
                view.setTextureForCell(i, j, 0);
                std::cout << "Clicked cell set :" << cellValue << std::endl;
            } else if (cellValue > 0) {
                view.setTextureForCell(i, j, cellValue);
                std::cout << "Number :" << cellValue << " set." << std::endl;
            }
        }
    }
}

void Controller::updateView() {
    for (unsigned int i = 0; i < model.getRows(); ++i) {
        for (unsigned int j = 0; j < model.getCols(); ++j) {
            int cellValue = model.getCellValue(i, j);
            //std::cout << cellValue << std::endl;
            view.setTextureForCell(i, j, cellValue);

        }
    }
}
