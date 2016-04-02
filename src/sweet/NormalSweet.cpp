#include "NormalSweet.hpp"

NormalSweet::NormalSweet(void)
  : Sweet("normal", NORMAL_VALUE, 's')
{
}

NormalSweet::~NormalSweet(void)
{
}

Sweet		*NormalSweet::clone(void)
{
  return (new NormalSweet());
}

void		NormalSweet::effect(Snake &player)
{
  player.feed(this->scoreValue);
}
