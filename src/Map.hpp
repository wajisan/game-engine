#ifndef MAP_HPP_
# define MAP_HPP_

#include <vector>

#include "sweet/SweetFactory.hpp"
#include "Snake.hpp"
#include "MyException.hpp"

class	Map
{
protected:
  const int	_x;
  const int	_y;
  std::string	_map;

public:
  Map(int x, int y);
  ~Map(void);

  int		addSweets(std::vector<Sweet*> &, Snake&);
  int		addSnake(Snake&);
  void		printMap(void);
  String	getMap(void);
  int		getXSize(void) const;
  int		getYSize(void) const;
};

#endif /* MAP_HPP_ */
