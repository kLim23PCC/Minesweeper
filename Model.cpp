#include "Model.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Model::Model(unsigned int rows, unsigned int cols, unsigned int mineCount)
    : rows(rows), cols(cols), mineCount(mineCount), grid(rows, std::vector<int>(cols, 11)) { // this sets the initial value for the grid
    std::srand(std::time(nullptr));
}

bool Model::isValidCell(unsigned int row, unsigned int col) const {
    return (row < rows && col < cols);
}

void Model::initializeMines(unsigned int firstRow, unsigned int firstCol) {
    placeMines(firstRow, firstCol);
}

void Model::placeMines(unsigned int firstRow, unsigned int firstCol) {
    unsigned int minesPlaced = 0;

    while (minesPlaced < mineCount) {
        unsigned int row = std::rand() % rows;
        unsigned int col = std::rand() % cols;

        // Ensure we're not placing a mine in the first clicked cell or its neighbors
        if (grid[row][col] == 10 ||  // Check for the new mine value
            (row >= firstRow - 1 && row <= firstRow + 1 &&
             col >= firstCol - 1 && col <= firstCol + 1)) {
            continue; // Skip if it's the first click area or already a mine
             }

        grid[row][col] = 10; // Place a mine (10 indicates a mine)
        minesPlaced++;
    }

    for (unsigned int row = 0; row < rows; row++) {
        for (unsigned int col = 0; col < cols; col++) {
            if (grid[row][col] == 10) continue; // Skip mines
            int adjacentMines = 0;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int adjRow = row + i;
                    int adjCol = col + j;
                    if (isValidCell(adjRow, adjCol) && grid[adjRow][adjCol] == 10) {
                        adjacentMines++;
                    }
                }
            }
            grid[row][col] = adjacentMines; // Store the number of adjacent mines
        }
    }
}


int Model::getCellValue(unsigned int row, unsigned int col) const {
    if (isValidCell(row, col)) {
        return grid[row][col];
    }
    return -1; // Or some other error code if out of bounds
}

void Model::setCellValue(unsigned int row, unsigned int col, int value) {
    if (isValidCell(row, col)) {
        grid[row][col] = value;
    }
}

bool Model::isMine(unsigned int row, unsigned int col) const {
    return grid[row][col] == 10;
}

int Model::revealCell(int row, int col) {
    return getCellValue(row, col);
}

bool Model::isCellRevealed(int row, int col) const {
    return isMine(row, col);
}

void Model::printGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << getCellValue(i, j) << ".";
        }
        std::cout << std::endl;
    }
}

