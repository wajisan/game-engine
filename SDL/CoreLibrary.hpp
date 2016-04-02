#ifndef CORELIBRARY_HPP
#define CORELIBRARY_HPP

#include <iostream>
#include <string>
#include <SDL/SDL.h>


class CoreLibrary
{
private:
  CoreLibrary(void);
  ~CoreLibrary(void);

  static CoreLibrary	*instance;
  int			cur_dir;
  int			map_x;
  int			map_y;

  SDL_Surface		*screen;
  SDL_Surface		*fond;
  SDL_Surface		*body;
  SDL_Surface		*fruit;
  SDL_Surface		*head;
  SDL_Surface		*sweet;
  SDL_Rect		pos;

public:
  static CoreLibrary	*getInstance(void);
  static void           destroyInstance(void);

  int			setData(int&, int, int);
  void			initLib(void);
  void			destroyLib(void);
  int			loadLib(void);
  int			unloadLib(void);
  int			eventLib(int &cur_dir);
  int			drawLib(std::string map, int size_x, int size_y);
  int			getmap_x(void);
};

#endif /*! CORELIBRARY_HPP */
