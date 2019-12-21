#include "Snake.h"
#include <random>

Snake::Snake()
	: snakePos(GameSettings::MaxSnakeSize, std::make_pair(0, 0))
    , AbstractHeadPos(std::make_pair(0, 0))
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> xDist(0, GameSettings::BoardWidth - 1);
    std::uniform_int_distribution<int> yDist(0, GameSettings::BoardHeight - 1);
    AbstractHeadPos = std::make_pair(xDist(rng), yDist(rng));
    snakePos[0] = AbstractHeadPos;
}

void Snake::ChangeHead()
{
    if (AbstractHeadPos != snakePos[headIndex]) {
        headIndex = (headIndex + 1) % snakeSize;
        snakePos[headIndex] = AbstractHeadPos;
    }
}

void Snake::ChangeHeadWithAddingSegment()
{
    if (AbstractHeadPos != snakePos[headIndex]) {
        headIndex += 1;
        snakeSize += 1;
        for (int i = snakeSize; i > headIndex; i--) {
            snakePos[i] = snakePos[i - 1];
        }
        snakePos[headIndex] = AbstractHeadPos;
    }
}

int Snake::HeadIndex() const
{
    return headIndex;
}

std::vector<std::pair<int, int>>& Snake::GetSnakePos()
{
    return snakePos;
}

int Snake::GetSnakeSize()
{
    return snakeSize;
}

bool Snake::CheakHeadIsNotEatTail()
{
    for (int i = 0; i < snakeSize; i++) {
        if (snakePos[headIndex] == snakePos[i] && i != headIndex) {
            return true;
        }
    }
    return false;
}

void Snake::Reset() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> xDist(0, GameSettings::BoardWidth - 1);
    std::uniform_int_distribution<int> yDist(0, GameSettings::BoardHeight - 1);
    AbstractHeadPos = std::make_pair(xDist(rng), yDist(rng));
    snakePos[0] = AbstractHeadPos;
    headIndex = 0;
    snakeSize = 1;
}
    
