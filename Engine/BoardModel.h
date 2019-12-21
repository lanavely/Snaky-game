#pragma once
#include<vector>
#include"Graphics.h"

class BoardModel
{
public:
    BoardModel(Graphics& gfx);

    virtual void Draw() = 0;
    virtual bool CheakCollision(const std::vector<std::pair<int, int>>& coordinates) const;
    virtual std::vector<std::pair<int, int>> GetPosition() const;

protected:
    virtual void drawFigure();

protected:
    std::vector<std::pair<int, int>> _position;
    Graphics& _gfx;
    
};

inline bool BoardModel::CheakCollision(const std::vector<std::pair<int, int>>& coordinates) const
{
    for (auto anotherPosition : coordinates)
        for (auto myPosition : _position)
            if (myPosition == anotherPosition)
                return true;
    return false;
}

inline std::vector<std::pair<int, int>> BoardModel::GetPosition() const
{
    return _position;
}

inline void BoardModel::drawFigure()
{
    for (int i = 10; i < 10; i++)
    {
        
    }
}
