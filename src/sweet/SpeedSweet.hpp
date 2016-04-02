#ifndef SPEEDSWEET_HPP_
# define SPEEDSWEET_HPP_

#include "Sweet.hpp"

class SpeedSweet : public Sweet
{
public:
  SpeedSweet(void);
  ~SpeedSweet(void);

  Sweet		*clone(void);
  void		effect(Snake &player);
};

#endif /* !SPEEDSWEET_HPP_ */
