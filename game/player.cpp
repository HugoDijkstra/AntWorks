#include <game/player.h>

Player::Player()
{

}
Player::Player(int w, int h)
{
        rect = new SDL_Rect();
        rect->h = h;
        rect->w = w;
        std::cout << "created" << std::endl;
}
Player::~Player()
{

}

/***
Update the player
***/
void Player::update(float dt)
{
        canWalkLeft = true;
        canWalkRight = true;
        canWalkUp = true;
        canWalkDown = true;

        //Check for each object you are touching if its in the yay of you walking
        for(unsigned int i = 0; i < collidingWith.size(); i++)
        {
                if(collidingWith[i]->pos.x > pos.x)
                        if(!dynamic_cast<Tile*>(collidingWith[i])->walkAble)
                        {
                                canWalkRight = false;
                        }
                if(collidingWith[i]->pos.x < pos.x)
                {

                        if(!dynamic_cast<Tile*>(collidingWith[i])->walkAble)
                        {
                                canWalkLeft = false;
                        }
                }
                if(collidingWith[i]->pos.y > pos.y)
                {
                        if(!dynamic_cast<Tile*>(collidingWith[i])->walkAble)
                        {
                                canWalkDown = false;
                        }
                }
                if(collidingWith[i]->pos.y < pos.y)
                {
                        if(!dynamic_cast<Tile*>(collidingWith[i])->walkAble)
                        {
                                canWalkUp = false;
                        }
                }

        }
//Get W key
        if(input->getKey(119))
        {
                if(canWalkUp)
                {
                        pos.y -= 100 * dt;
                }

        }
        else //Get S key
        if(input->getKey(115) && canWalkDown)
        {
                pos.y += 100 * dt;
        }
//Get A key
        if(input->getKey(97) && canWalkLeft)
        {
                pos.x -= 100 * dt;
        }
        else //Get D key
        if(input->getKey(100) && canWalkRight)
        {
                pos.x += 100 * dt;
        }
        rect->y = pos.y;
        rect->x = pos.x;
        collidingWith.clear();
}
