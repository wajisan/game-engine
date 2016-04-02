#include "Graph.hpp"

Graph::Graph(void)
{
  SDL_Init(SDL_INIT_VIDEO);

  this->screen = SDL_SetVideoMode(1280, 960, 32, SDL_OPENGL);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, 1280/960, 1, 1000);
}

Graph::~Graph(void)
{
}

void		Graph::drawPlan(int px, int py, int pz)
{
  (void)pz;
  glBegin(GL_QUADS);
  glColor3ub(12, 12, 12);
  glVertex3i(px, py, 0);
  glVertex3i(px + UNIT, py, 0);
  glVertex3i(px + UNIT, py - UNIT , 0);
  glVertex3i(px, py - UNIT, 0);
  glEnd();
}

void		Graph::drawOutline(int px, int py, int pz)
{
  glBegin(GL_LINES);
  glColor3ub(50, 198, 216);
  glVertex3i(px, py, pz);
  glVertex3i(px + UNIT, py, pz);
  glVertex3i(px + UNIT, py, pz);
  glVertex3i(px + UNIT, py - UNIT , pz);
  glVertex3i(px + UNIT, py - UNIT , pz);
  glVertex3i(px, py - UNIT, pz);
  glVertex3i(px, py - UNIT, pz);
  glVertex3i(px, py, pz);
  glEnd();
}
