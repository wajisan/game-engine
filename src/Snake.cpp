#include <stdlib.h>
#include "Snake.hpp"

Snake::Snake(int x, int y)
{
  memset(this->direction, 0, NB_DIR);
  this->direction[LEFT] = -1;
  this->direction[RIGHT] = 1;
  this->direction[TOP] = -x;
  this->direction[DOWN] = x;
  this->cur_dir = LEFT;
  this->pos_h = ((x * y) + x ) / 2;
  this->size = Options::getInstance()->getOption(Options::SNAKE_SIZE);
  this->_life = Options::getInstance()->getOption(Options::LIFE);
  this->_baseSpeed = Options::getInstance()->getOption(Options::SPEED);
  this->_speed = _baseSpeed;
  this->pos_t = ((x * y) + x ) / 2 + this->size;
  this->fed = false;
  this->timeSpeed = -1;
  this->crash = false;
}

Snake::~Snake(void)
{
}

lua_State*	Snake::getLua()
{
  return (this->L);
}

int		Snake::update(int map_x, int map_y, lua_State* _L)
{
  this->L = _L;
  if (this->isCrash())
    return (1);
  if (!this->_speed)
    {
      if (this->move(map_x, map_y))
	return (1);
      this->_speed = Options::getInstance()->getOption(Options::SPEED);;
    }
  this->_speed--;
  this->timeSpeed --;
  if (this->timeSpeed == 0)
    {
      Options::getInstance()->setOption(Options::SPEED, _baseSpeed);
      this->timeSpeed = -1;
    }
  return (0);
}

int		Snake::isCrash(void)
{
  if (this->crash == true)
    this->_life--;
  this->crash = false;
  if (this->_life == 0)
    exit(0);
  return (0);
}

int		Snake::buffSpeed(int value, int time)
{
  this->timeSpeed = time;
  this->_speed -= value;
  if (this->_speed < 1)
    this->_speed = 1;
  Options::getInstance()->setOption(Options::SPEED, _speed);
  return (0);
}

void		Snake::setCrash(void)
{
  this->crash = true;
}

void		Snake::moveRight(int map_x, std::vector<int>::iterator it)
{
  if ((*it + this->direction[cur_dir]) % map_x == 0 && cur_dir == RIGHT)
    {
      if (Options::getInstance()->getOption(Options::WALL))
	this->crash = true;
      else
	positions.push_back(*it - (map_x - 1));
    }
}

void		Snake::moveLeft(int map_x, std::vector<int>::iterator it)
{
  if ((*it % map_x == 0 && *it > 0) && cur_dir == LEFT)
    {
      if (Options::getInstance()->getOption(Options::WALL))
	this->crash = true;
      else
	positions.push_back(*it + (map_x - 1));
    }
}

void		Snake::moveTop(int map_x, int map_y,
			       std::vector<int>::iterator it)
{
  if ((*it + this->direction[cur_dir]) <= 0)
    {
      if (Options::getInstance()->getOption(Options::WALL))
	this->crash = true;
      else
	positions.push_back((map_x * (map_y - 1)) + (*it % map_x));
    }
}

void		Snake::moveDown(int map_x, int map_y,
				std::vector<int>::iterator it)
{
  if ((*it + this->direction[cur_dir]) >= (map_x * map_y))
    {
      if (Options::getInstance()->getOption(Options::WALL))
	this->crash = true;
      else
	positions.push_back((*it % map_x));
    }
}

int		Snake::move(int map_x, int map_y)
{
  int				i = 0;
  std::vector<int>::iterator	it;

  if (this->positions.empty())
    {
      for (i = this->pos_t; i >= this->pos_h; --i)
	positions.push_back(i);
    }
  else
    {
      it = positions.end() - 1;
      unsigned int last_size = positions.size();
      this->moveRight(map_x, it);
      this->moveLeft(map_x, it);
      this->moveDown(map_x, map_y, it);
      this->moveTop(map_x, map_y, it);
      if (positions.size() == last_size)
	positions.push_back((*it) + this->direction[cur_dir]);
      else
	this->size++;
      if (!this->fed)
	positions.erase(positions.begin());
      else
	this->fed = false;
    }
  return (this->crash == true ? 1 : 0);
}

std::vector<int>::iterator	Snake::getHead(void)
{
  return (this->positions.begin());
}

std::vector<int>::iterator	Snake::getTail(void)
{
  return (this->positions.end());
}

void				Snake::feed(int value)
{
  this->fed = true;
  this->size += value;
}

int				&Snake::getDirection(void)
{
  return (this->cur_dir);
}

int	Snake::getHx() const
{
  return (this->pos_h);
}

int	Snake::getTx() const
{
  return (this->pos_t);
}

int	Snake::getSize() const
{
  return (this->size);
}
