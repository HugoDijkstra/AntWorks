#ifndef ENTITY
#define ENTITY

#include <hugworks/vector2.h>
#include <hugworks/input.h>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

class Entity
{
public:
        //Constructor & Deconstuctor
        Entity();
        Entity(int w, int h);
        virtual ~Entity();
        //Posistion and size
        Vector2 pos;
        SDL_Rect* rect;

        std::vector<Entity*> collidingWith;

        //Color
        int r,g,b,a;

        //id
        int id;

        //input
        Input* input;

        //functions
        int getId(){
                return id;
        };
        static bool check_collision( SDL_Rect* A, SDL_Rect* B );
        virtual void update(float dt);
private:
        static int ids;
};

#endif
