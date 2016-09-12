#ifndef SCENE
#define SCENE

#include <SDL.h>
#include <hugworks/entity.h>
#include <hugworks/input.h>
#include <hugworks/layer.h>
#include <vector>


class Scene
{
public:

        //Constructor & Deconstuctor
        Scene();
        virtual ~Scene();

        Input* input;
        void setInput(Input* in)
        {
                input = in;
        };
        //Entity list
        std::vector<Entity*> entities;
        std::vector<Layer*> layers;
        void addEntity(Entity* entity);
private:
};

#endif
