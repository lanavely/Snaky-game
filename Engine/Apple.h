#pragma once
#include <utility>

class Apple
{
public:
    Apple();
    std::pair<int, int> GetApplePos();
    void ChangeAppleToRandomPos();
    void Reset();
private:
    std::pair<int, int> applePos;
};

