#ifndef TILE
#define TILE

#include <hugworks/entity.h>

class Tile : public Entity
{
public:
  //Constructor & Deconstuctor
  Tile();
  virtual ~Tile();

  //booleans
  bool walkAble = true;

  //ints
  int type = 0;

private:


};

#endif
