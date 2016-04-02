#include <string>
#include "CoreLibrary.hpp"
#include <stdlib.h>

CoreLibrary	*CoreLibrary::instance = NULL;

void		my_error(const char *str)
{
  endwin();
  std::cerr << str << std::endl;
  exit(EXIT_FAILURE);
}

CoreLibrary::CoreLibrary(void)
{
  this->initLib();
}

CoreLibrary::~CoreLibrary(void)
{
  endwin();
}

void			CoreLibrary::initLib(void)
{
  initscr();
  if (keypad(stdscr, TRUE) == ERR)
    my_error("Keypad func");
  if (noecho() == ERR)
    my_error("Noecho func");
  if (curs_set(0) == ERR)
    my_error("Curs_set func");
  timeout(1);
}

void			CoreLibrary::destroyLib(void)
{
  if (endwin() == ERR)
    my_error("Endwin func");
  // fermeture de la lib
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
    {
      if (endwin() == ERR)
	my_error("Endwin func");
      delete instance;
    }
  instance = NULL;
}

int			CoreLibrary::loadLib(void)
{
  // Chargement de toutes les images, textures
  return (0);
}

int			CoreLibrary::unloadLib(void)
{
  return (0);
  // Free de toutes les images, textures
}

int			CoreLibrary::eventLib(int &cur_dir)
{
  int		c;

  //std::cout << cur_dir << std::endl;;
  c = getch();
  switch (c)
    {
    case KEY_LEFT:
      cur_dir = cur_dir + 1 > 3 ? 0 : cur_dir + 1;
      return (0);
    case KEY_RIGHT:
      cur_dir = cur_dir - 1 < 0 ? 3 : cur_dir - 1;
      return (0);
    case KEY_ESC:
      {
	this->destroyLib();
	return (1);
      }
      default:
	return (0);
    }
  // Fonction pour gerer les touches
}

void			wall(int size_x)
{
  for (int i = 0; i <= size_x; ++i)
    {
      attron(COLOR_PAIR(4));
      printw(" ");
    }
}
int			CoreLibrary::drawLib(std::string map, 
					     int size_x, int size_y)
{
  clear();
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_BLACK, COLOR_BLACK);
  init_pair(4, COLOR_WHITE, COLOR_WHITE);
  init_pair(5, COLOR_BLUE, COLOR_BLUE);
  if (start_color() == ERR)
    my_error("Start_color func");
  if (refresh() == ERR)
    my_error("Refresh func");
  wall(size_x);
  for (int i = 0; i <= (size_x * size_y); ++i)
    {
      if (i % size_x == 0)
	{
	  attron(COLOR_PAIR(4));
	  if (printw(" \n ") == ERR)
	    my_error("Printw func");
	}
      if (map[i] == 'o')
	attron(COLOR_PAIR(2));
      else if (map[i] == 's' || map[i] == 'H')
	attron(COLOR_PAIR(1));
      else if (map[i] == 'f')
	attron(COLOR_PAIR(5));
      else
	attron(COLOR_PAIR(3));
      if (printw("%c", map[i]) == ERR)
	my_error("Printw func");
    }
  wall(size_x);
  refresh();
  usleep(20000);
  return (0);
}
