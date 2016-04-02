#ifndef CORELIBRARY_HPP
#define CORELIBRARY_HPP

#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <map>

#include "Graph.hpp"

#define		MILLI_SEC	1000
#define		FPS		60

class CoreLibrary
{
private:
  CoreLibrary(void);
  ~CoreLibrary(void);

  static CoreLibrary	*instance;
  Graph			*graph;
  void			*map;
  int			fps_time;
  int			current_fps;
  bool			pause;
public:
  static CoreLibrary	*getInstance(void);
  static void		destroyInstance(void);

  void			initLib(void);
  void			destroyLib(void);
  int			loadLib(void);
  int			unloadLib(void);
  int			eventLib(int &cur_dir);
  void			drawMap(std::string, int, int, int);
  void			drawPLayer(std::string, int, int, int);
  void			drawSweets(std::string, int, int, int);
  int			drawLib(std::string, int, int);
};

#endif /*! CORELIBRARY_HPP */
