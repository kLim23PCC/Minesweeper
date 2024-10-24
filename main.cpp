#include <SFML/Graphics.hpp>
#include "Model.h"
#include "View.h"
#include "Controller.h"
#include "Minesweeper.h"

int main() {
    const unsigned int rows = 10;
    const unsigned int cols = 10;
    const unsigned int mineCount = 10;
    const float cellSize = 70.0f;

    Model model(rows, cols, mineCount);

    sf::Texture texture;
    if (!texture.loadFromFile("minesweep_cut.png")) {
        exit(1);
    }

    View view(rows, cols, cellSize, texture);
    Controller controller(model, view, cellSize);

    Minesweeper minesweeper(816, 748, "Minesweeper", controller, view);
    minesweeper.run();

    return 0;
}
