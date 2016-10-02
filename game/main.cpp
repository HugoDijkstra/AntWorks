#include <hugworks/renderer.h>
#include <hugworks/scene.h>
#include <hugworks/entity.h>
#include <game/player.h>
#include <game/tile.h>
#include <game/grass.h>
#include <iostream>

Renderer* renderer;
Scene* scene;
Input* input;
Player* entity;


int main()
{
        if(SDL_Init(SDL_INIT_VIDEO) == 0)
        {
                std::cout << "Init done" << std::endl;
        }
        else
        {
                std::cout << "Init fault : " << SDL_GetError() << std::endl;
        }

        renderer = new Renderer(1000, 700);
        scene = new Scene();
        input = new Input();
        entity = new Player(40,40);
        entity->r = 255;
        entity->g = 0;
        entity->b = 255;
        entity->a = 255;
        entity->rect->h = 20;
        entity->rect->w = 20;
        entity->rect->y = 100;
        entity->rect->x = 100;
        entity->pos.x = 100;
        entity->pos.y = 100;

        int currentLayer = 5;


        scene->setInput(input);
        entity->input = input;
        for(unsigned int i = 0; i < 10; i++)
        {
                scene->layers.push_back(new Layer());
        }
        for(unsigned int l = 0; l < 10; l++)
                for(unsigned int i = 0; i < 30; i++)
                {
                        for(unsigned int j = 0; j < 30; j++)
                        {
                                scene->layers[l]->addEntity(new Grass((30 * i), (30 * j)));
                        }
                }
        scene->addEntity(entity);
        while(!input->mustquit)
        {
                input->update();
                if(input->getKeyDown(91))
                {
                        if(currentLayer <= 8)
                        {
                                currentLayer++;
                                std::cout << currentLayer << std::endl;
                        }
                }
                if(input->getKeyDown(93))
                {
                        if(currentLayer >= 1)
                        {
                                currentLayer--;
                                std::cout << currentLayer << std::endl;
                        }
                }
                renderer->renderScene(scene, currentLayer);
                for(unsigned int i = 0; i < scene->layers[currentLayer]->entities.size(); i++)
                {
                        if(Entity::check_collision(scene->layers[currentLayer]->entities[i]->rect, entity->rect))
                        {
                                entity->collidingWith.push_back(scene->layers[currentLayer]->entities[i]);
                                scene->layers[currentLayer]->entities[i]->collidingWith.push_back(entity);
                        }
                }
        }
        scene->layers.clear();
        SDL_Quit();
        delete entity;
        delete input;
        delete renderer;
        delete scene;
}
