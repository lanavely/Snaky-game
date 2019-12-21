#pragma once
#include "Graphics.h"
#include <vector>
#include <utility>

class Drawer
{
public:
    Drawer(Graphics& gfx);

public:
    void DrawApple(std::pair<int, int> applePos);
    void DrawSnake(std::vector<std::pair<int, int>> snakePos, int snakesize, int snakeHead);

private:
    void drawSquare(std::pair<int, int> pos, int r, int g, int b);
    void drawSquare(std::pair<int, int> pos, Color c);
    Graphics& gfx;
    int SqueareSize = 0;
    int margin = 2;
};

