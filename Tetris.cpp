#include <iostream>
#include "Tetris.h"
#include "Block.h"
#include "LongBlock.h"
#include "BoxBlock.h"

using namespace std;

enum CommandType
{
    LEFT,
    RIGHT,
    DOWN,
    TURN
};

enum BlockType
{
    LONG,
    BOX,
    last_type
};

void SetRandomActiveBlock();
bool BlockInLegalState(Block block);
bool RunCommand(CommandType commandType);
bool BlockWithinWorldBounds(Block block);
bool BlockIntersectsAnyStaticBlock(Block block);

Block* _activeBlock;
vector<Block> _staticBlocks;
int _worldHeight = 20;
int _worldWidth = 10;

Tetris::Tetris(){
    SetRandomActiveBlock();
}

vector<vector<Color*>> Tetris::GetGameState() {
    vector<vector<Color*>> gameState = vector<vector<Color*>>();

    // Initialize vector with nulls
    for (int i = 0; i < _worldHeight; ++i) {
        vector<Color*> line;
        for (int j = 0; j < _worldHeight; ++j) {
            line.push_back(NULL);
        }
        gameState.push_back(line);
    }

    for (int k = 0; k < _staticBlocks.size(); ++k) {
        Block block = _staticBlocks[k];
        vector<Point> blockVector = block.WorldVector();
        for (int p = 0; p < blockVector.size(); ++p) {
            Point point = blockVector[p];
            gameState[point.Y][point.X] = new Color(block._color);
        }
    }

    return gameState;
}

void Tetris::Update() {
    bool downMoveSuccessful = RunCommand(DOWN);
    if (!downMoveSuccessful)
    {
        _staticBlocks.push_back(*_activeBlock);
        SetRandomActiveBlock();
    }
}

void Tetris::CommandLeft() {
    RunCommand(LEFT);
}

void Tetris::CommandRight() {
    RunCommand(RIGHT);
}

void Tetris::CommandDown() {
    RunCommand(DOWN);
}

void Tetris::CommandTurn() {
    RunCommand(TURN);
}

int Tetris::Width() {
    return _worldWidth;
}

int Tetris::Height() {
    return _worldHeight;
}

bool RunCommand(CommandType commandType)
{
    Block* tmpBlock = new Block(*_activeBlock);

    switch (commandType)
    {
        case LEFT:
            tmpBlock->MoveLeft();
            break;
        case RIGHT:
            tmpBlock->MoveRight();
            break;
        case DOWN:
            tmpBlock->MoveDown();
            break;
        case TURN:
            tmpBlock->Turn();
            break;
    }

    if (BlockInLegalState(*tmpBlock))
    {
        _activeBlock = tmpBlock;
        return true;
    }
    return false;
}

void SetRandomActiveBlock()
{

    Point initialBlockPoint = {.X = _worldWidth/2 - 1, .Y = _worldHeight};
    BlockType randomType = static_cast<BlockType>(rand() % last_type);
    switch (randomType)
    {
        case LONG:
            _activeBlock = new LongBlock(initialBlockPoint);
            break;
        case BOX:
            _activeBlock = new BoxBlock(initialBlockPoint);
            break;
    }
}

bool BlockInLegalState(Block block)
{
    if (!BlockWithinWorldBounds(block)) return false;
    if (!BlockIntersectsAnyStaticBlock(block)) return false;

    return true;
}

bool BlockWithinWorldBounds(Block block)
{
    vector<Point> blockVector = block.WorldVector();

    for (int i = 0; i < blockVector.size(); ++i) {
        Point p = blockVector[i];
        if (p.X > _worldWidth || p.X < 0 || p.Y > _worldHeight || p.Y < 0) return true;
    }
    return false;
}

bool BlockIntersectsAnyStaticBlock(Block block)
{
    vector<Point> blockVector = block.WorldVector();
    for (int i = 0; i < blockVector.size(); ++i) {
        Point blockPoint = blockVector[i];
        for (int j = 0; j < _staticBlocks.size(); ++j) {
            vector<Point> comparisonBlockVector = _staticBlocks[j].WorldVector();
            for (int k = 0; k < comparisonBlockVector.size(); ++k) {
                Point comparisonPoint = comparisonBlockVector[k];
                if (blockPoint == comparisonPoint) return true;
            }
        }
    }
    
    return false;
}





