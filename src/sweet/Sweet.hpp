#ifndef SWEET_HPP_
# define SWEET_HPP_

#include <string>

#include "../Snake.hpp"

#define		NORMAL_VALUE	1
#define		SPEED_VALUE	2

class Sweet
{
protected:
  std::string		name;
  int			scoreValue;
  int			pos;
  char			value;

public:
  Sweet(void);
  Sweet(std::string, int, char);
  Sweet(const Sweet&);
  virtual ~Sweet(void);

  virtual Sweet	&operator=(const Sweet&);

  std::string	getName(void) const;
  int		getScoreValue(void) const;
  int		getPos(void) const;
  void		setPos(int pos);
  char		getValue(void) const;

  virtual Sweet	*clone(void);
  virtual void	effect(Snake &player);
};

#endif /* !SWEET_HPP_ */
