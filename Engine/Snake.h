#pragma once
#include "GameSettings.h"
#include <utility>
#include <vector>

class Snake
{
public:
	Snake();
public:
	std::pair<int, int> AbstractHeadPos;
	void ChangeHead();
	void ChangeHeadWithAddingSegment();
    int HeadIndex() const;
	std::vector<std::pair<int, int>>& GetSnakePos();
    int GetSnakeSize();
    bool CheakHeadIsNotEatTail();
    void Reset();
private:
	std::vector<std::pair<int, int>> snakePos;
	int headIndex = 0;
	int snakeSize = 1;
};

