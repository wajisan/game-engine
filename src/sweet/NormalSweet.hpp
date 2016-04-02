#ifndef NORMALSWEET_HPP_
# define NORMALSWEET_HPP_

#include "Sweet.hpp"

class NormalSweet : public Sweet
{
public:
  NormalSweet(void);
  ~NormalSweet(void);

  Sweet			*clone(void);
  void			effect(Snake &player);
};

#endif /* !NORMALSWEET_HPP_ */
