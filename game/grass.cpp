#include <game/grass.h>

Grass::Grass(int x, int y)
{
        pos.x = x;
        pos.y = y;
        rect->w = 30;
        rect->h = 30;
        r = 0;
        b = 0;
        g = 255;
        a = 255;
        digTime = 0.5f;
        walkAble = false;
}
Grass::~Grass()
{

}

void Grass::update(float dt)
{
        //Set posistion of rect to posistion
        rect->x = pos.x;
        rect->y = pos.y;

        //Check if coliding with anything
        if(collidingWith.size() > 0)
        {
          //if is coliding subtract delta time from dig time
          digTime -= dt;
        }
        if(digTime <= 0)
        {
          r = 0;
          b = 0;
          g = 0;
          a = 255;
          this->walkAble = true;
        }
        collidingWith.clear();
}
