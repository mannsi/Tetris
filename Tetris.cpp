#include <iostream>
#include "Tetris.h"
#include "Block.h"

using namespace std;

Block* _activeBlock;

vector<vector<Color*>> Tetris::GetGameState() {
    cout << "Get game state" << endl;
    Color* red = new Color(1.0, 0.0, 0.0);
    Color* green = new Color(0.0, 1.0, 0.0);
    Color* blue = new Color(0.0, 0.0, 1.0);

    vector<vector<Color*>> gameState = vector<vector<Color*>>();
    gameState.push_back({NULL, red, red, red, NULL, NULL, blue, blue, NULL, green});
    gameState.push_back({NULL, NULL, red, NULL, NULL, NULL, NULL, blue, NULL, green});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, blue, NULL, green});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, green});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    gameState.push_back({NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL});
    return gameState;
}

void Tetris::Update() {
    cout << "Update" << endl;

    // Try to move active piece down
    // IF YES
    //  Update active piece
    // IF NO
    //  Generate new piece and set it as active piece
}

void Tetris::CommandLeft() {
    cout << "Left" << endl;
}

void Tetris::CommandRight() {
    cout << "Right" << endl;
}

void Tetris::CommandDown() {
    cout << "Down" << endl;
}

void Tetris::CommandTurn() {
    cout << "Turn" << endl;
}

int Tetris::Width() {
    return 10;
}

int Tetris::Height() {
    return 20;
}