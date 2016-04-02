#include "SweetFactory.hpp"

SweetFactory	*SweetFactory::instance = NULL;

SweetFactory::SweetFactory(void)
{
  this->loadFactory();
  this->_timer = 0;
  this->_maxSweets = 2;
}

SweetFactory::~SweetFactory(void)
{
  delete this->products[NORMAL];
  delete this->products[SPEED];
}

SweetFactory		*SweetFactory::getInstance(void)
{
  if (!instance)
    instance = new SweetFactory();
  return instance;
}

void			SweetFactory::destroyInstance(void)
{
  if (instance)
    {
      delete instance;
      instance = NULL;
    }
}

void			SweetFactory::loadFactory(void)
{
  this->products[NORMAL] = new NormalSweet();
  this->products[SPEED] = new SpeedSweet();
}

void			SweetFactory::generSweet(std::vector<Sweet*> &sweets,
						  std::string map,
						  unsigned int size)
{
  int			rand_pos;
  int			rand_type;
  Sweet			*new_sweet;
  clock_t		current;

  current = clock();
  if (!_timer || ((float)(current - _timer)) / 1000 > TIMER ||
      !sweets.size())
    {
      if (sweets.size() < _maxSweets)
	{
	  rand_pos = rand() % (size - 1);
	  rand_type = rand() % NB_PRODUCTS;
	  if (map[rand_pos] == '.')
	    {
	      new_sweet = this->products[rand_type]->clone();
	      new_sweet->setPos(rand_pos);
	      sweets.push_back(new_sweet);
	    }
	}
      this->_timer = clock();
    }
}
