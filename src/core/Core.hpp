#ifndef CORE_HPP_
# define CORE_HPP_

extern "C" {
#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <lua5.2/lualib.h>
}

#include <iostream>
#include <string>
#include <dlfcn.h>
#include <sstream>
#include <vector>

#include "../Snake.hpp"
#include "../Map.hpp"
#include "../sweet/SweetFactory.hpp"
#include "../Options.hpp"

#define		EVENT_SYM	"_Z5eventRi"
#define		DRAW_SYM	"_Z4drawSsii"
#define		DESTROY_SYM	"_Z7destroyv"
#define		DATA_SYM	"_Z7setDataRiii"

class Core
{
protected:

  lua_State*		L;
  Map			*map;
  Snake			*player;
  std::vector<Sweet*>	sweets;

  int			(*ptr_event)(int&);
  int			(*ptr_draw)(std::string, int, int);
  int			(*ptr_destroy)(void);
  int			(*ptr_setData)(int &, int, int);

public:
  Core(void);
  ~Core(void);

  void		load(int ac, char **av, const char* lua_script);
  int		unload(void);
  void		loadMap();
  void		loadSnake(void);
  void		loadLibrary(char **av);
  int		run(void);
};

#endif /*!CORE_HPP_*/
