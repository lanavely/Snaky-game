/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <cmath>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
    drawer(gfx),
    directionMgr(wnd)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    if (gameOver) {
        if (!wnd.kbd.KeyIsPressed(VK_SPACE)) {
            return;
        }
        directionMgr.Reset();
        snake.Reset();
        apple.Reset();
        gameOver = false;
    }
    
    directionMgr.GetDirection();
    directionMgr.MovePosition(snake.AbstractHeadPos);
    if (snake.AbstractHeadPos == apple.GetApplePos()) {
        snake.ChangeHeadWithAddingSegment();
        apple.ChangeAppleToRandomPos();
    }
    else if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
        snake.ChangeHeadWithAddingSegment();
    }
    else {
        snake.ChangeHead();
    }
    gameOver = snake.CheakHeadIsNotEatTail();
}

void Game::ComposeFrame()
{
    drawer.DrawSnake(snake.GetSnakePos(), snake.GetSnakeSize(), snake.HeadIndex());
    drawer.DrawApple(apple.GetApplePos());
}   