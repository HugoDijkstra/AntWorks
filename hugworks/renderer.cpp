#include <hugworks/renderer.h>

/***
When created without arguments set the window size to 640X480
***/
Renderer::Renderer()
{
        this->windowWidht = 480;
        this->windowHeight = 640;

        if(this->init()) ;
        {
                std::cout << "renderer created." << std::endl;
        }
}

/***
When created with arguments set window to wXH
***/
Renderer::Renderer(int w, int h)
{
        this->windowWidht = w;
        this->windowHeight = h;

        if(this->init()) ;
        {
                std::cout << "renderer created." << std::endl;
        }
}

/***
Deconstructor
***/
Renderer::~Renderer()
{
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
}

/***
Initiation code to setup the window and renderer
***/
bool Renderer::init()
{
        //Create window
        window = SDL_CreateWindow("HugWorks", 0,0,windowWidht, windowHeight,0);
        //Check if windows equals NULL
        if(window == NULL)
        {
                std::cout << "Error in setting up window " << SDL_GetError() << std::endl;
                return false;
        }
        //Create renderer
        renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_SOFTWARE);
        //Check if renderer equals NULL
        if(renderer == NULL)
        {
                std::cout << "Error in setting up renderer " << SDL_GetError() << std::endl;
                return false;
        }
        //Render first image to fill background
        SDL_RenderPresent(renderer);
        //if all succesfull return funciton true;
        return true;
}

/***
Render the layer of the scene given as arguments
***/
void Renderer::renderScene(Scene* scene,int layer)
{
        //Render to black to clear the whole screen
        SDL_RenderClear(renderer);
        //Update deltaTime
        updateDeltaTime();

        //renderer and update the ground of the current layer
        for(unsigned int i = 0; i < scene->layers[layer]->entities.size();i++)
        {
          //update the tile
          scene->layers[layer]->entities[i]->update(deltatTime);

          //set the drawColor to the color of the current object
          SDL_SetRenderDrawColor(renderer, scene->layers[layer]->entities[i]->r,scene->layers[layer]->entities[i]->g,scene->layers[layer]->entities[i]->b,scene->layers[layer]->entities[i]->a);
          //fill the current opject and put it on the render bufffer;
          SDL_RenderFillRect(renderer, scene->layers[layer]->entities[i]->rect);
        }
        //Do the same for the non background objects
        for(unsigned int i = 0; i < scene->entities.size(); i++)
        {
                scene->entities[i]->update(deltatTime);
                SDL_SetRenderDrawColor(renderer, scene->entities[i]->r,scene->entities[i]->g,scene->entities[i]->b,scene->entities[i]->a);
                SDL_RenderFillRect(renderer, scene->entities[i]->rect);
        }
        // Set render color to black
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        //render the current renderbuffer
        SDL_RenderPresent(renderer);
}
/***
calculate the time between this and the last frame
***/
void Renderer::updateDeltaTime()
{
        double now = SDL_GetTicks();
        deltatTime = (now - lastTime) / 1000;
        lastTime = now;
}
