#include "Apple.h"
#include "GameSettings.h"
#include <random>


Apple::Apple()
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> xDist(0, GameSettings::BoardWidth - 1);
    std::uniform_int_distribution<int> yDist(0, GameSettings::BoardHeight - 1);
    applePos = std::make_pair(xDist(rng), yDist(rng));
}

std::pair<int, int> Apple::GetApplePos()
{
    return applePos;
}

void Apple::ChangeAppleToRandomPos()
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> xDist(0, GameSettings::BoardWidth - 1);
    std::uniform_int_distribution<int> yDist(0, GameSettings::BoardHeight - 1);
    applePos = std::make_pair(xDist(rng), yDist(rng));
}

void Apple::Reset()
{
    ChangeAppleToRandomPos();
}
