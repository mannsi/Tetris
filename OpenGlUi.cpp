#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <math.h>
#include "OpenGlUi.h"
#include "BoxShape.h"
#include <vector>

using namespace std;

void update(int value);
void enable2D(int width, int height);
void drawBox(Color color, BoxShape box);
BoxShape getDrawableBox(int xGrid, int yGrid);
void KeyPressed(unsigned char, int, int);
void KeyUp(unsigned char, int, int);
void draw();

int number_of_chars = 256;
Tetris* _tetris;
bool* keyStates = new bool[number_of_chars];

const float window_width = 500;
const float window_height = 1000;
const int update_interval = 1000 / 3;
int gridWidth;
int gridHeight;
float gridCellWidth;
float gridCellHeight;
vector<vector<Color*>> gameState;


void show_ui(Tetris* tetris, int argc, char *argv[])
{
    _tetris = tetris;
    gridWidth = tetris->Width();
    gridHeight = tetris->Height();
    gridCellWidth = (window_width / gridWidth);
    gridCellHeight = (window_height / gridHeight);
    gameState = tetris->GetGameState();

    std::fill_n(keyStates, number_of_chars, false);
    // initialize opengl (via glut)
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("MF Pong");

    // Register callback functions
    glutDisplayFunc(draw);
    glutTimerFunc(update_interval, update, 0);
    glutKeyboardFunc(KeyPressed);

    // setup scene to 2d mode and set draw color to white
    enable2D(window_width, window_height);
    glColor3f(1.0f, 1.0f, 1.0f);

    // start the whole thing
    glutMainLoop();
}

void enable2D(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
}

void draw() {
    // clear (has to be done at the beginning)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    for (int i = 0; i < gridHeight; ++i) {
        for (int j = 0; j < gridWidth; ++j) {
            if (gameState[i][j] != NULL)
            {
                Color color = *gameState[i][j];
                drawBox(color, getDrawableBox(j, i));
            }
        }
    }

    // swap buffers (has to be done at the end)
    glutSwapBuffers();
}

void drawBox(Color color, BoxShape box) {
    glColor3f(color.R, color.G, color.B);
    glBegin(GL_QUADS);
    glVertex2f(box.x, box.y);
    glVertex2f(box.x + box.width, box.y);
    glVertex2f(box.x + box.width, box.y + box.height);
    glVertex2f(box.x, box.y + box.height);
    glEnd();
}

BoxShape getDrawableBox(int xGrid, int yGrid)
{
    int widthBufferBetweenCells = 2;
    float cell_x_start = xGrid * gridCellWidth;
    float cell_y_start = yGrid * gridCellHeight;

    BoxShape drawableBox = BoxShape();
    drawableBox.x = cell_x_start + widthBufferBetweenCells/2;
    drawableBox.y = cell_y_start + widthBufferBetweenCells/2;
    drawableBox.width = gridCellWidth - widthBufferBetweenCells;
    drawableBox.height = gridCellHeight - widthBufferBetweenCells;
    return drawableBox;
}

void update(int value) {
    // Call update() again in 'interval' milliseconds
    glutTimerFunc(update_interval, update, 0);

    _tetris->Update();
    gameState = _tetris->GetGameState();

    // Redisplay frame
    glutPostRedisplay();
}

void KeyPressed (unsigned char key, int x, int y) {
    (*_tetris).KeyPressed(key);
}
