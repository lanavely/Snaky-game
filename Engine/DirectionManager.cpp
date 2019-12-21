#include "DirectionManager.h"
#include "GameSettings.h"

DirectionManager::DirectionManager(MainWindow & wnd)
    : wnd(wnd), pressedDirections(4, false)
{
}

void DirectionManager::GetDirection()
{
    if (!directionQueue.OverflowDirection()) {
        if (!wnd.kbd.KeyIsEmpty()) {
            Direction dir = readKey();
            if (dir != UNDEFINED && dir != prevDir){
                directionQueue.Queue(dir);
                prevDir = dir;
            }
        }
    }
}

void DirectionManager::MovePosition(std::pair<int, int>& position)
{
    countLastFrames = countLastFrames % GameSettings::CountFrameForMove + 1;
    if (countLastFrames / GameSettings::CountFrameForMove) {
        switch (directionQueue.Dequeue())
        {
        case(LEFT):
            position.first -= 1;
            break;
        case(UP):
            position.second -= 1;
            break;
        case(RIGHT):
            position.first += 1;
            break;
        case(DOWN):
            position.second += 1;
            break;
        default:
            break;
        } 
        changeHeadIfCollisionWithBorders(position);
    }
}

void DirectionManager::Reset()
{
    directionQueue.Reset();
    prevDir = UNDEFINED;
}

void DirectionManager::changeHeadIfCollisionWithBorders(std::pair<int, int>& position)
{
    if (position.first < 0) {
        position.first = GameSettings::BoardWidth - 1;
    }
    else if (position.second < 0) {
        position.second = GameSettings::BoardHeight - 1;
    }
    else if (position.first >= GameSettings::BoardWidth) {
        position.first = 0;
    }
    else if (position.second >= GameSettings::BoardHeight) {
        position.second = 0;
    }
}

Direction DirectionManager::readKey() {
    if (wnd.kbd.KeyIsPressed('W') || wnd.kbd.KeyIsPressed(VK_UP)) {
        if (!pressedDirections[0]) {
            pressedDirections[0] = true;
            return UP;
        }
    }
    else {
        pressedDirections[0] = false;
    }
    if (wnd.kbd.KeyIsPressed('A') || wnd.kbd.KeyIsPressed(VK_LEFT)) {
        if (!pressedDirections[1]) {
            pressedDirections[1] = true;
            return LEFT;
        }
    }
    else {
        pressedDirections[1] = false;
    }
    if (wnd.kbd.KeyIsPressed('S') || wnd.kbd.KeyIsPressed(VK_DOWN)) {
        if (!pressedDirections[2]) {
            pressedDirections[2] = true;
            return DOWN;
        }
    }
    else {
        pressedDirections[2] = false;
    }
    if (wnd.kbd.KeyIsPressed('D') || wnd.kbd.KeyIsPressed(VK_RIGHT)) {
        if (!pressedDirections[3]) {
            pressedDirections[3] = true;
            return RIGHT;
        }
    }
    else {
        pressedDirections[3] = false;
    }
    return UNDEFINED;
}
