#ifndef RENDERER
#define RENDERER

#include <SDL.h>
#include <hugworks/scene.h>
#include <hugworks/input.h>
#include <iostream>
#include <vector>

class Renderer
{
public:
  //Constructors and Deconstuctor
  Renderer();
  Renderer(int w, int h);
  virtual ~Renderer();

  //Window dementions
  int windowHeight, windowWidht;

  //Sdl dependensies
  SDL_Window* window;
  SDL_Renderer* renderer;

  //delta time
  double deltatTime;
  double lastTime;

  //functions
  bool init();
  void renderScene(Scene* scene, int layer);
  void updateDeltaTime();
  double getDeltaTime();

private:

};

#endif
