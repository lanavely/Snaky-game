#pragma once
#include "Direction.h"
#include "DirectionQueue.h"
#include "MainWindow.h"
#include <utility>
#include <vector>

class DirectionManager
{
public:
    DirectionManager(MainWindow& wnd);
public:
    void GetDirection();
    void MovePosition(std::pair<int, int>& position);
    void Reset();
private:
    void changeHeadIfCollisionWithBorders(std::pair<int, int>& Position);
private:
    DirectionQueue directionQueue;
    MainWindow& wnd;
    Direction prevDir = UNDEFINED;
    int countLastFrames = 0;
    Direction readKey();
    std::vector<bool> pressedDirections;
};

