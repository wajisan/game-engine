#ifndef SNAKE_HPP_
# define SNAKE_HPP_

#define KEY_ESC		27
#define	NB_DIR		4

extern "C" {
#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <lua5.2/lualib.h>
}

#include <iostream>
#include <string.h>
#include <vector>

#include "Options.hpp"

class	Snake
{
  typedef	enum {
    LEFT,
    DOWN,
    RIGHT,
    TOP,
  }		e_etat;
  
protected:

  lua_State*		L;
  int			pos_h;
  int			pos_t;
  int			size;
  int			_life;
  int			_baseSpeed;
  int			_speed;
  int			timeSpeed;
  bool			fed;
  e_etat		etat;
  int			direction[NB_DIR];
  int			cur_dir;
  bool			crash;
  std::vector<int>	positions;

public:
  Snake(int x, int y);
  ~Snake();

  lua_State*			getLua();
  int				update(int, int, lua_State*);
  int				isCrash(void);
  int				buffSpeed(int, int);
  int				move(int, int);
  void				moveRight(int, std::vector<int>::iterator);
  void				moveLeft(int, std::vector<int>::iterator);
  void				moveDown(int, int, std::vector<int>::iterator);
  void				moveTop(int, int, std::vector<int>::iterator);

  void				setCrash(void);
  std::vector<int>::iterator	getHead(void);
  std::vector<int>::iterator	getTail(void);
  void				feed(int);
  int				&getDirection(void);
  int				getHx(void) const;
  int				getTx(void) const;
  int				getSize(void) const;
};

#endif /* SNAKE_HPP_ */
