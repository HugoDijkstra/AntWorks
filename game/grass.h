#ifndef GRASS
#define GRASS

#include <game/tile.h>
#include <iostream>

class Grass : public Tile
{
public:
  Grass(int x, int y);
  ~Grass();
  float digTime;
  virtual void update(float dt);
private:

};

#endif
