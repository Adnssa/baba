#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Player.h"
#include "Game.h"


#define JUMP_ANGLE_STEP 4
#define JUMP_HEIGHT 96
#define FALL_STEP 4


enum PlayerAnims
{
	STAND_LEFT, STAND_RIGHT, STAND_UP, STAND_DOWN, MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN};


void Player::init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram)
{
	bJumping = false;
	
	spritesheet[0].loadFromFile("images/Baba_sheet.png", TEXTURE_PIXEL_FORMAT_RGBA);
	sprite[0] = Sprite::createSprite(glm::ivec2(32, 32), glm::vec2(1/32.f, 1/66.f), &spritesheet[0], &shaderProgram);
	sprite[0]->setNumberAnimations(4);

	sprite[0]->setAnimationSpeed(STAND_LEFT, 4);
	sprite[0]->addKeyframe(STAND_LEFT, glm::vec2(10 / 32.f, 0.f));
	sprite[0]->addKeyframe(STAND_LEFT, glm::vec2(10 / 32.f, 1/66.f));
	sprite[0]->addKeyframe(STAND_LEFT, glm::vec2(10 / 32.f, 2/66.f));

	sprite[0]->setAnimationSpeed(STAND_RIGHT, 4);
	sprite[0]->addKeyframe(STAND_RIGHT, glm::vec2(0.f, 0.f));
	sprite[0]->addKeyframe(STAND_RIGHT, glm::vec2(0.f, 1 / 66.f));
	sprite[0]->addKeyframe(STAND_RIGHT, glm::vec2(0.f, 2 / 66.f));

	sprite[0]->setAnimationSpeed(STAND_UP, 4);
	sprite[0]->addKeyframe(STAND_UP, glm::vec2(5 / 32.f, 0.f));
	sprite[0]->addKeyframe(STAND_UP, glm::vec2(5 / 32.f, 1 / 66.f));
	sprite[0]->addKeyframe(STAND_UP, glm::vec2(5 / 32.f, 2 / 66.f));

	sprite[0]->setAnimationSpeed(STAND_DOWN, 4);
	sprite[0]->addKeyframe(STAND_DOWN, glm::vec2(15 / 32.f, 0.f));
	sprite[0]->addKeyframe(STAND_DOWN, glm::vec2(15 / 32.f, 1 / 66.f));
	sprite[0]->addKeyframe(STAND_DOWN, glm::vec2(15 / 32.f, 2 / 66.f));

	sprite[0]->setAnimationSpeed(MOVE_LEFT, 16);
	sprite[0]->addKeyframe(MOVE_LEFT, glm::vec2(10/32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_LEFT, glm::vec2(11/32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_LEFT, glm::vec2(12/32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_LEFT, glm::vec2(13/32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_LEFT, glm::vec2(14 / 32.f, 0.f));

	sprite[0]->setAnimationSpeed(MOVE_RIGHT, 16);
	sprite[0]->addKeyframe(MOVE_RIGHT, glm::vec2(0.f, 0.f));
	sprite[0]->addKeyframe(MOVE_RIGHT, glm::vec2(1 / 32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_RIGHT, glm::vec2(2 / 32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_RIGHT, glm::vec2(3 / 32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_RIGHT, glm::vec2(4 / 32.f, 0.f));


	sprite[0]->setAnimationSpeed(MOVE_UP, 16);
	sprite[0]->addKeyframe(MOVE_UP, glm::vec2(5 / 32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_UP, glm::vec2(6 / 32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_UP, glm::vec2(7 / 32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_UP, glm::vec2(8 / 32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_UP, glm::vec2(9 / 32.f, 0.f));

	sprite[0]->setAnimationSpeed(MOVE_DOWN, 16);
	sprite[0]->addKeyframe(MOVE_DOWN, glm::vec2(15/ 32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_DOWN, glm::vec2(16 / 32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_DOWN, glm::vec2(17 / 32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_DOWN, glm::vec2(18 / 32.f, 0.f));
	sprite[0]->addKeyframe(MOVE_DOWN, glm::vec2(19 / 32.f, 0.f));

	sprite[0]->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite[0]->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));




	spritesheet[1].loadFromFile("images/bub.png", TEXTURE_PIXEL_FORMAT_RGBA);
	sprite[1] = Sprite::createSprite(glm::ivec2(32, 32), glm::vec2(0.25, 0.25), &spritesheet[1], &shaderProgram);
	sprite[1]->setNumberAnimations(4);
	
	sprite[1]->setAnimationSpeed(STAND_LEFT, 8);
	sprite[1]->addKeyframe(STAND_LEFT, glm::vec2(0.f, 0.f));
		
	sprite[1]->setAnimationSpeed(STAND_RIGHT, 8);
	sprite[1]->addKeyframe(STAND_RIGHT, glm::vec2(0.25f, 0.f));
		
	sprite[1]->setAnimationSpeed(MOVE_LEFT, 8);
	sprite[1]->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.f));
	sprite[1]->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.25f));
	sprite[1]->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.5f));
		
	sprite[1]->setAnimationSpeed(MOVE_RIGHT, 8);
	sprite[1]->addKeyframe(MOVE_RIGHT, glm::vec2(0.25, 0.f));
	sprite[1]->addKeyframe(MOVE_RIGHT, glm::vec2(0.25, 0.25f));
	sprite[1]->addKeyframe(MOVE_RIGHT, glm::vec2(0.25, 0.5f));
		
	sprite[1]->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite[1]->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
	
}

void Player::update(int deltaTime, int p)
{
	player = p;
	sprite[player]->update(deltaTime);
	if(Game::instance().getSpecialKey(GLUT_KEY_LEFT))
	{
		if(sprite[player]->animation() != MOVE_LEFT)
			sprite[player]->changeAnimation(MOVE_LEFT);
		posPlayer.x -= 2;
		if(map->collisionMoveLeft(posPlayer, glm::ivec2(32, 32)))
		{
			posPlayer.x += 2;
			sprite[player]->changeAnimation(STAND_LEFT);
		}
	}
	else if(Game::instance().getSpecialKey(GLUT_KEY_RIGHT))
	{
		if(sprite[player]->animation() != MOVE_RIGHT)
			sprite[player]->changeAnimation(MOVE_RIGHT);
		posPlayer.x += 2;
		if(map->collisionMoveRight(posPlayer, glm::ivec2(32, 32)))
		{
			posPlayer.x -= 2;
			sprite[player]->changeAnimation(STAND_RIGHT);
		}
	}
	else
	{
		if(sprite[player]->animation() == MOVE_LEFT)
			sprite[player]->changeAnimation(STAND_LEFT);
		else if(sprite[player]->animation() == MOVE_RIGHT)
			sprite[player]->changeAnimation(STAND_RIGHT);
		else if (sprite[player]->animation() == MOVE_UP)
			sprite[player]->changeAnimation(STAND_UP);
		else if (sprite[player]->animation() == MOVE_DOWN)
			sprite[player]->changeAnimation(STAND_DOWN);
	}
	
	sprite[player]->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
}

void Player::render()
{
	sprite[player]->render();
}

void Player::setTileMap(TileMap *tileMap)
{
	map = tileMap;
}

void Player::setPosition(const glm::vec2 &pos)
{
	posPlayer = pos;
	sprite[player]->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
}




