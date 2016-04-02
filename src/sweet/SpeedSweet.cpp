#include "SpeedSweet.hpp"

SpeedSweet::SpeedSweet(void)
  : Sweet("speed", 15, 'f')
{
}

SpeedSweet::~SpeedSweet(void)
{
}

Sweet		*SpeedSweet::clone(void)
{
  return (new SpeedSweet());
}

void		SpeedSweet::effect(Snake &player)
{
  player.feed(this->scoreValue);
  player.buffSpeed(1, 50);
}
