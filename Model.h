//
// Created by klimz on 10/22/2024.
//

#ifndef MODEL_H
#define MODEL_H

#include <vector>

class Model {
public:
    Model(unsigned int rows, unsigned int cols, unsigned int mineCount);

    void initializeMines(unsigned int firstRow, unsigned int firstCol);
    int getCellValue(unsigned int row, unsigned int col) const;
    void setCellValue(unsigned int row, unsigned int col, int value);
    unsigned int getRows() const { return rows; }
    unsigned int getCols() const { return cols; }
    bool isMine(unsigned int row, unsigned int col) const;
    int revealCell(int row, int col);
    bool isCellRevealed(int row, int col) const;
    void printGrid();
private:
    unsigned int rows, cols, mineCount;
    std::vector<std::vector<int>> grid; // 10 for mine, 0+ for number of adjacent mines

    void placeMines(unsigned int firstRow, unsigned int firstCol); // Helper for mine placement
    bool isValidCell(unsigned int row, unsigned int col) const; // Utility to check if row, col are within bounds
};

#endif // MODEL_H

