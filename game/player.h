#ifndef PLAYER
#define PLAYER

#include <SDL.h>
#include <hugworks/entity.h>
#include <game/tile.h>
#include <iostream>

class Player : public Entity
{
public:
  Player();
  Player(int w, int h);
  virtual ~Player();

  bool canWalkLeft, canWalkRight, canWalkUp, canWalkDown;

  virtual void update(float dt);
private:
};

#endif
