#include <string>
#include "CoreLibrary.hpp"
#include <stdlib.h>

CoreLibrary	*CoreLibrary::instance = NULL;

CoreLibrary::CoreLibrary(void)
{
  this->initLib();
}

CoreLibrary::~CoreLibrary(void)
{
  this->destroyLib();
}

void			CoreLibrary::initLib(void)
{
  this->graph = new Graph();
  this->pause = false;
}

void			CoreLibrary::destroyLib(void)
{
  if (this->graph)
    {
      delete this->graph;
      this->graph = NULL;
    }
}

CoreLibrary		*CoreLibrary::getInstance(void)
{
  if (instance == NULL)
    return (instance = new CoreLibrary());
  return (instance);
}

void			CoreLibrary::destroyInstance(void)
{
  if (instance)
    delete instance;
  instance = NULL;
}

int			CoreLibrary::eventLib(int &cur_dir)
{
  SDL_Event		event;

  if (this->pause == true)
    {
      while (this->pause == true)
	{
	  SDL_PollEvent(&event);
	  if (event.type == SDL_KEYDOWN &&
	      event.key.keysym.sym == SDLK_RETURN)
	    {
	      this->pause = false;
	    }
	}
    }
  this->fps_time = SDL_GetTicks();
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
	return (1);
      else if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_LEFT)
	    cur_dir = cur_dir + 1 > 3 ? 0 : cur_dir + 1;
	  else if (event.key.keysym.sym == SDLK_RIGHT)
	    cur_dir = cur_dir - 1 < 0 ? 3 : cur_dir - 1;
	  else if (event.key.keysym.sym == SDLK_RETURN)
	    this->pause = true;
	  return (0);
	}
    }
  return (0);
}

void			CoreLibrary::drawMap(std::string map, int pos,
					     int size_x, int size_y)
{
  if (map[pos] != '*')
    {
      this->graph->drawPlan((0 - (size_x / 2)) + (pos % (size_x)),
			    (size_y / 2) - (pos / size_x),
			    0);
      this->graph->drawOutline((0 - (size_x / 2)) + (pos % (size_x)),
			       (size_y / 2) - (pos / size_x),
			       0);
    }
}

void			CoreLibrary::drawPLayer(std::string map, int pos,
						int size_x, int size_y)
{
  GLUquadric *params = NULL;

  if (map[pos] == 'o' || map[pos] == 'H')
    {
      params = gluNewQuadric();
      gluQuadricDrawStyle(params, GLU_FILL);
      map[pos] == 'o' ? glColor3ub(208, 243, 45)
	: glColor3ub(236, 139, 35);
      glTranslatef((0 - (size_x / 2)) + (pos % (size_x)) + 0.5,
		   (size_y / 2) - (pos / size_x) - 0.5,
		   0.5);
      gluSphere(params, 0.5, 15, 15);
      glTranslatef(0 - ((0 - (size_x / 2)) + (pos % (size_x))) - 0.5,
		   0 - ((size_y / 2) - (pos / size_x)) + 0.5,
		   -0.5);
      gluDeleteQuadric(params);
    }
}

void			CoreLibrary::drawSweets(std::string map, int pos,
						int size_x, int size_y)
{
  GLUquadric *params = NULL;

  if (map[pos] == 's' || map[pos] == 'f')
    {
      params = gluNewQuadric();
      gluQuadricDrawStyle(params, GLU_FILL);
      map [pos] == 's' ? glColor3ub(232, 111, 111)
	: glColor3ub(178, 90, 188);
      glTranslatef((0 - (size_x / 2)) + (pos % (size_x)) + 0.5,
		   (size_y / 2) - (pos / size_x) - 0.5,
		   0.5);
      gluSphere(params, 0.5, 15, 15);
      glTranslatef(0 - ((0 - (size_x / 2)) + (pos % (size_x))) - 0.5,
		   0 - ((size_y / 2) - (pos / size_x)) + 0.5,
		   -0.5);
      gluDeleteQuadric(params);
    }
}

int			CoreLibrary::drawLib(std::string map,
					     int size_x, int size_y)
{
  float lightDif[4] = {1, 1, 1, 0};
  int LightPos[4] = {0,-25,30,1};

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, -25, 30, 0, 0, 0, 0, 0, 1);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
  glLightiv(GL_LIGHT0, GL_POSITION, LightPos);
  for (int i = 0; i < size_x * size_y; i++)
    {
      this->drawMap(map, i, size_x, size_y);
      glEnable(GL_DEPTH_TEST);
      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glEnable(GL_COLOR_MATERIAL);
      this->drawPLayer(map, i, size_x, size_y);
      this->drawSweets(map, i, size_x, size_y);
      glDisable(GL_DEPTH_TEST);
      glDisable(GL_LIGHTING);
      glDisable(GL_LIGHT0);
    }
  this->current_fps = MILLI_SEC / (SDL_GetTicks() - this->fps_time);
  // std::cout << this->current_fps << std::endl;
  if (SDL_GetTicks() - this->fps_time < MILLI_SEC / FPS)
    SDL_Delay((MILLI_SEC / FPS) - (SDL_GetTicks() - this->fps_time));
  glFlush();
  SDL_GL_SwapBuffers();
  return (0);
}
