#ifndef SWEETFACTORY_HPP_
# define SWEETFACTORY_HPP_

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Sweet.hpp"
#include "NormalSweet.hpp"
#include "SpeedSweet.hpp"

#define		NB_PRODUCTS	2
#define		TIMER		600

class SweetFactory
{
private:
  SweetFactory(void);
  ~SweetFactory(void);

  typedef enum		e_type
    {
      NORMAL,
      SPEED
    }			e_type;

  static SweetFactory	*instance;
  Sweet			*products[NB_PRODUCTS];
  clock_t		_timer;
  unsigned int		_maxSweets;

public:

  static SweetFactory		*getInstance(void);
  static void			destroyInstance(void);

  void				loadFactory(void);
  void				generSweet(std::vector<Sweet*> &,
					    std::string, unsigned int);
};

#endif /* !SWEETFACTORY_HPP_ */
