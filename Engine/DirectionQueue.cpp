#include "DirectionQueue.h"
#include "GameSettings.h"


DirectionQueue::DirectionQueue()
    : directions(GameSettings::MaxDirectionQueue, UNDEFINED)
{
}

void DirectionQueue::Queue(Direction direction)
{
    if (idx < GameSettings::MaxDirectionQueue)
    {
        if (idx > 0) {
            if (direction == -directions[idx - 1]) {
                return;
            }
        }
        directions[idx] = direction;
        idx += 1;
    }
}

Direction DirectionQueue::Dequeue()
{
    Direction result = directions[0];
    if (idx > 1) {
        idx -= 1;
        for (int i = 0; i < idx; i++) {
            directions[i] = directions[i + 1];
        }
    }
    return result;
}

bool DirectionQueue::OverflowDirection()
{
    return idx - 1 == GameSettings::MaxDirectionQueue;
}

void DirectionQueue::Reset()
{
    directions[0] = UNDEFINED;
    idx = 0;
}





