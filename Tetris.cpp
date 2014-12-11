#include <iostream>
#include "Tetris.h"
#include "Block.h"
#include "LongBlock.h"
#include "BoxBlock.h"
#include "TBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "LBlock.h"
#include "JBlock.h"

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
    T,
    S,
    Z,
    L,
    J,
    last_type
};

Block*GetRandomActiveBlock();
bool BlockInLegalState(Block block);
bool RunCommand(CommandType commandType);
bool BlockWithinWorldBounds(Block block);
bool BlockIntersectsAnyStaticBlock(Block block);
void AddBlockToVector(Block block, vector<vector<Color*>>& vec);
void InitializeStaticColorVector();
void RemoveWholeLines();
vector<Color*> GetEmptyColorLine();


Block* _activeBlock;
vector<vector<Color*>> _staticColorVector;
int _worldHeight = 20;
int _worldWidth = 10;
bool _gameFinished = false;

Tetris::Tetris(){
    InitializeStaticColorVector();
    _activeBlock = GetRandomActiveBlock();
}

void InitializeStaticColorVector()
{
    // Initialize vector with nulls
    for (int i = 0; i < _worldHeight + 2; ++i) {
        vector<Color*> line = GetEmptyColorLine();
        _staticColorVector.push_back(line);
    }
}

vector<Color*> GetEmptyColorLine()
{
    vector<Color*> line;
    for (int j = 0; j < _worldWidth; ++j) {
        line.push_back(NULL);
    }
    return line;
}

vector<vector<Color*>> Tetris::GetGameState() {
    vector<vector<Color*>> gameState = vector<vector<Color*>>(_staticColorVector);
    AddBlockToVector(*_activeBlock, gameState);
    return gameState;
}

void Tetris::Update() {
    if (_gameFinished) return;

    bool downMoveSuccessful = RunCommand(DOWN);
    if (!downMoveSuccessful)
    {
        AddBlockToVector(*_activeBlock, _staticColorVector);
        RemoveWholeLines();
        _activeBlock = GetRandomActiveBlock();
        _gameFinished = !BlockInLegalState(*_activeBlock);
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

Block* GetRandomActiveBlock()
{
    Point initialBlockPoint = {.X = _worldWidth/2 - 2, .Y = _worldHeight};
    BlockType randomType = static_cast<BlockType>(rand() % last_type);
    Block* block;
    switch (randomType)
    {
        case LONG:
            block = new LongBlock(initialBlockPoint);
            break;
        case BOX:
            block = new BoxBlock(initialBlockPoint);
            break;
        case T:
            block = new TBlock(initialBlockPoint);
            break;
        case S:
            block = new SBlock(initialBlockPoint);
            break;
        case Z:
            block = new ZBlock(initialBlockPoint);
            break;
        case L:
            block = new LBlock(initialBlockPoint);
            break;
        case J:
            block = new JBlock(initialBlockPoint);
            break;
    }

    return block;
}

bool BlockInLegalState(Block block)
{
    if (!BlockWithinWorldBounds(block)) return false;
    if (BlockIntersectsAnyStaticBlock(block)) return false;

    return true;
}

bool BlockWithinWorldBounds(Block block)
{
    vector<Point> blockVector = block.WorldVector();

    for (int i = 0; i < blockVector.size(); ++i) {
        Point p = blockVector[i];
        if (p.X >= _worldWidth || p.X < 0 || p.Y < 0) return false;
    }
    return true;
}

bool BlockIntersectsAnyStaticBlock(Block block)
{
    vector<Point> blockVector = block.WorldVector();
    for (int p = 0; p < blockVector.size(); ++p) {
        Point point = blockVector[p];
        if(_staticColorVector[point.Y][point.X] != NULL) return true;
    }

    return false;
}

void AddBlockToVector(Block block, vector<vector<Color*>>& vec)
{
    vector<Point> blockVector = block.WorldVector();
    for (int p = 0; p < blockVector.size(); ++p) {
        Point point = blockVector[p];
        Color* color = new Color(block._color);
        vec[point.Y][point.X] = color;
    }
}

void RemoveWholeLines()
{
    for (int lineNumber = 0; lineNumber < _staticColorVector.size(); ++lineNumber) {
        vector<Color*> line = _staticColorVector[lineNumber];
        bool lineShouldBeRemoved = true;
        for (int itemNumber = 0; itemNumber < line.size(); ++itemNumber) {
            if (line[itemNumber] == NULL)
            {
                lineShouldBeRemoved = false;
            }
        }
        if (lineShouldBeRemoved)
        {
            _staticColorVector.erase(_staticColorVector.begin()+lineNumber);
            vector<Color*> line = GetEmptyColorLine();
            _staticColorVector.push_back(line);
            lineNumber--;
        }
    }
}

