#include "Drawer.h"
#include "GameSettings.h"
#include "Graphics.h"
#include "Colors.h"

Drawer::Drawer(Graphics& gfx)
    : gfx(gfx)
{
    SqueareSize = Graphics::ScreenWidth / GameSettings::BoardWidth;
}

void Drawer::DrawApple(std::pair<int, int> applePos)
{
    drawSquare(applePos, Colors::Red);
}

void Drawer::DrawSnake(std::vector<std::pair<int, int>> snakePos, int snakesize, int snakeHead)
{
    for (int i = 0; i < snakesize; i++) {
        drawSquare(snakePos[i], Colors::Green);
    }
    drawSquare(snakePos[snakeHead], Colors::Yellow);
}

void Drawer::drawSquare(std::pair<int, int> pos, int r, int g, int b)
{
    for (int i = pos.first * SqueareSize + margin; i < pos.first * SqueareSize + SqueareSize - margin; i++) {
        for (int j = pos.second * SqueareSize + margin; j < pos.second * SqueareSize + SqueareSize - margin; j++) {
            gfx.PutPixel(i, j, r, g, b);
        }
    }
}

void Drawer::drawSquare(std::pair<int, int> pos, Color c)
{
    for (int i = pos.first * SqueareSize + margin; i < pos.first * SqueareSize + SqueareSize - margin; i++) {
        for (int j = pos.second * SqueareSize + margin; j < pos.second * SqueareSize + SqueareSize - margin; j++) {
            gfx.PutPixel(i, j, c);
        }
    }
}

