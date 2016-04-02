#ifndef GRAPH_HPP_
# define GRAPH_HPP_

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#define		UNIT	1

class Graph
{
private:
  SDL_Surface	*screen;

public:
  Graph(void);
  ~Graph(void);

  void		drawPlan(int, int, int);
  void		drawOutline(int, int, int);
};

#endif /*! GRAPH_HPP */
