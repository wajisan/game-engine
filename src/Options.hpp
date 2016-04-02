#ifndef OPTIONS_HPP_
# define OPTIONS_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "MyException.hpp"

#define			NB_OPTIONS	4
#define			D_SNAKE_SIZE	4
#define			D_WALL		1
#define			D_LIFE		1
#define			D_SPEED		5

class Options
{
public:

  typedef enum		e_options
    {
      SNAKE_SIZE,
      WALL,
      LIFE,
      SPEED
    }			e_options;

private:
  Options(void);
  ~Options(void);

  static Options			*_instance;
  int					_options[NB_OPTIONS];
  std::map<std::string, e_options>	_ident;

public:

  static Options	*getInstance(void);
  static void		destroyInstance(void);

  void			loadIdent(void);
  void			loadDefaultOptions(void);
  void			parse(int, char **);
  void			setOption(e_options, int);
  int			getOption(e_options) const;
};

#endif /* OPTIONS_HPP_ */
