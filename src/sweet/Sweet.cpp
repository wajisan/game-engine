#include "Sweet.hpp"

Sweet::Sweet(void)
{
}

Sweet::Sweet(std::string name, int scoreValue, char value)
  : name(name), scoreValue(scoreValue), value(value)
{
}

Sweet::Sweet(const Sweet &model)
{
  this->name = model.name;
  this->scoreValue = model.getScoreValue();
  this->value = model.value;
}

Sweet::~Sweet(void)
{
}

Sweet		&Sweet::operator=(const Sweet &model)
{
  this->name = model.getName();
  this->scoreValue = model.getScoreValue();
  this->value = model.value;
  return (*this);
}

Sweet		*Sweet::clone(void)
{
  return (new Sweet());
}

void		Sweet::effect(Snake &player)
{
  player.feed(this->scoreValue);
}

int		Sweet::getPos(void) const
{
  return (this->pos);
}

void		Sweet::setPos(int pos)
{
  this->pos = pos;
}

std::string	Sweet::getName(void) const
{
  return (this->name);
}

char		Sweet::getValue(void) const
{
  return (this->value);
}

int		Sweet::getScoreValue(void) const
{
  return (this->scoreValue);
}
