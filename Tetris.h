#ifndef TETRIS_H
#define TETRIS_H

#include <vector>
#include "Color.h"

class Tetris
{
public:
    Tetris();

    /// Updates the game by one 'step'
    void Update();

    /// Commands that affect game state
    void CommandLeft();
    void CommandRight();
    void CommandDown();
    void CommandTurn();

    /// Get a color vector with dimensions [Height, Width]. Color value null means there should be no box in that part of the grid
    std::vector<std::vector<Color*>> GetGameState();

    /// Width of the Tetris world
    int Width();

    /// Height of the Tetris world
    int Height();
};

#endif