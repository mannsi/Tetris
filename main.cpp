#include <iostream>
#include "Tetris.h"
#include "OpenGlUi.h"

using namespace std;

int main(int argc, char **argv) {
    Tetris* tetris = new Tetris();
    show_ui(tetris, argc, argv);

    return 0;
}