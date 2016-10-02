#ifndef INVENTORY
#define INVENTORY

#include <game/item.h>

class Inventory
{
public:
  Inventory();
  ~Inventory();
        std::vector<Item*> items;
private:
}

#endif
