#include <GL/glew.h>
#include <GL/glut.h>
#include "Game.h"


void Game::init()
{
	bPlay = true;
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	scene.init();
	menu.init();
	player = ZELDA;
}

bool Game::update(int deltaTime)
{
	if (state == STATE_PLAYING) scene.update(deltaTime, player);
	else  menu.update(deltaTime);
	return bPlay; 
	
	return bPlay;
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (state == STATE_MENU || state == STATE_CREDITS) menu.render(state);
	else scene.render();
}

void Game::keyPressed(int key)
{
	if(key == 27) // Escape code
		bPlay = false;
	keys[key] = true;
}

void Game::keyReleased(int key)
{
	if (key == 9) player = (player + 1) % 2;
	if (key == 32) {
		if (state == STATE_MENU) state = STATE_PLAYING;
		else if (state == STATE_PLAYING) state = STATE_CREDITS;
	}
	keys[key] = false;
}

void Game::specialKeyPressed(int key)
{
	specialKeys[key] = true;
}

void Game::specialKeyReleased(int key)
{
	
	specialKeys[key] = false;
}

void Game::mouseMove(int x, int y)
{
}

void Game::mousePress(int button)
{
}

void Game::mouseRelease(int button)
{
}

bool Game::getKey(int key) const
{
	return keys[key];
}

bool Game::getSpecialKey(int key) const
{
	return specialKeys[key];
}





