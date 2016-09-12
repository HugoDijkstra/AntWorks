#ifndef LAYER
#define LAYER

#include <vector>
#include <hugworks/entity.h>
class Layer
{
public:
  Layer();
  virtual ~Layer();
  std::vector<Entity*> entities;

  void addEntity(Entity* entity);

private:

};

#endif
