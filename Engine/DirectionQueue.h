#pragma once
#include"Direction.h"
#include<vector>
class DirectionQueue
{
public:
    DirectionQueue();

public:
    void Queue(Direction direction);
    Direction Dequeue();
    bool OverflowDirection();
    void Reset();
private:
    std::vector<Direction> directions;
    int idx = 0;
};

