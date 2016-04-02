#include <map>

#include "Map.hpp"

Map::Map(int x, int y)
  : _x(x), _y(y), _map((x * y), '.')
{ 
  if (x < 10 || y < 10 || x > 40 || y > 40)
    throw (MyException("Invalid size"));
}

Map::~Map(void)
{
}

int		Map::addSweets(std::vector<Sweet*> &sweets,
				Snake &player)
{
  std::vector<Sweet*>::iterator		it;
  int					pos;

  for (it = sweets.begin(); it < sweets.end(); ++it)
    {
      pos = (*it)->getPos();
      if (this->_map[pos] == 'H')
	{
	  (*it)->effect(player);
	  delete (*it);
	  sweets.erase(it);
	}
      else
	this->_map[pos] = (*it)->getValue();
    }
  return (0);
}

String		Map::getMap(void)
{
  return (this->_map);
}

int		Map::addSnake(Snake &player)
{
  std::vector<int>::iterator	it;

  this->_map.assign((this->_x * this->_y), '.');
  for (it = player.getHead(); it != player.getTail(); ++it)
    {
      if (this->_map[*it] == '.')
	it == player.getTail() - 1 ? this->_map[*it] = 'H'
	  : this->_map[*it] = 'o';
      else if (this->_map[*it] == 'H' || this->_map[*it] == 'o')
	{
	  player.setCrash();
	  return (1);
	}
    }
  return (0);
}

void		Map::printMap(void)
{
  for (unsigned int i = 0; i <= this->_map.size(); ++i)
    {
      if (i % this->_y == 0)
	std::cout << std::endl;
      std::cout << this->_map[i];
    }
}

int		Map::getXSize(void) const
{
  return (this->_x);
}

int		Map::getYSize(void) const
{
  return (this->_y);
}
