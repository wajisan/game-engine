#include "Core.hpp"

int x_map = 0;
int y_map = 0;

Core::Core(void)
{
  this->map = NULL;
  this->player = NULL;
}

Core::~Core(void)
{
}

int l_setMap(lua_State* L) {
  x_map = luaL_checknumber(L, 1);
  y_map = luaL_checknumber(L, 2);
  return 0;
}


void		Core::load(int ac, char **av, const char *lua_script)
{
  if (ac != 2)
    throw(MyException("Usage: ./nibbler [library.so]"));
  

  /* LUA LUA */

  this->L = luaL_newstate();
  luaL_openlibs(L); // load default Lua libs

  if (luaL_loadfile(L, lua_script))
    throw(MyException("Error loading script : "));

  lua_pushcfunction(L, l_setMap);
  lua_setglobal(L, "setMap");
  lua_pcall(L, 0, 0, 0);

  /* END */
  
 
  this->loadMap();
  this->loadSnake();
  this->loadLibrary(av);
}

int		Core::unload(void)
{
  if (this->map)
    delete this->map;
  if (this->player)
    delete this->player;
  this->ptr_destroy();
  return (1);
}

void		Core::loadMap()
{
  this->map = new Map(x_map, y_map);
}

void		Core::loadSnake(void)
{
  this->player = new Snake(this->map->getXSize(),
			   this->map->getYSize());
}

void		Core::loadLibrary(char **av)
{
  void		*lib = NULL;

  if ((lib = dlopen(av[1], RTLD_LAZY)) == NULL)
    throw(MyException("dlopen failed (" + String(dlerror()) + ")"));
  *(void **)(&this->ptr_event) = dlsym(lib, EVENT_SYM);
  *(void **)(&this->ptr_draw) = dlsym(lib, DRAW_SYM);
  *(void **)(&this->ptr_destroy) = dlsym(lib, DESTROY_SYM);
  *(void **)(&this->ptr_setData) = dlsym(lib, DATA_SYM);
  if (*this->ptr_event == NULL || *this->ptr_draw == NULL ||
      *this->ptr_destroy == NULL)
    throw(MyException("dlsym : symbol not found"));
}

int		Core::run(void)
{
  while (1)
    {
      if (*this->ptr_setData)
	this->ptr_setData(this->player->getDirection(), this->map->getXSize(),
			  this->map->getXSize());
      if (this->ptr_event(this->player->getDirection()))
	return (unload());
      if (this->player->update(this->map->getXSize(),
			       this->map->getYSize(), this->L))
	return (unload());
      if (this->map->addSnake(*this->player))
	return (unload());

      SweetFactory::getInstance()->generSweet(this->sweets, this->map->getMap(),
					      this->map->getXSize() * this->map->getYSize());
      this->map->addSweets(this->sweets, *this->player);
      this->ptr_draw(this->map->getMap(), this->map->getXSize(),
		     this->map->getYSize());
    }
  return (0);
}
