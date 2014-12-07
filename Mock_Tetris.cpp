#include <iostream>
#include "Tetris.h"

using namespace std;

Tetris::Tetris(){
    cout << "Constructor" << endl;
}

vector<vector<Color*>> Tetris::GetGameState() {
    Color* red =  new Color(1.0, 0.0, 0.0);
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