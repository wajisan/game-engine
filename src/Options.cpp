#include "Options.hpp"

Options		*Options::_instance = NULL;

Options::Options(void)
{
  this->loadIdent();
  this->loadDefaultOptions();
}

Options::~Options(void)
{
}

Options		*Options::getInstance(void)
{
  if (!_instance)
    _instance = new Options();
  return (_instance);
}

void		Options::destroyInstance(void)
{
  if (_instance)
    delete _instance;
  _instance = NULL;
}

void		Options::loadIdent(void)
{
  _ident["-Wall"] = WALL;
  _ident["-Psize"] = SNAKE_SIZE;
  _ident["-Plife"] = LIFE;
  _ident["-Pspeed"] = SPEED;
}

void		Options::loadDefaultOptions(void)
{
  _options[SNAKE_SIZE] = D_SNAKE_SIZE;
  _options[WALL] = D_WALL;
  _options[LIFE] = D_LIFE;
  _options[SPEED] = D_SPEED;
}

void		Options::parse(int ac, char **av)
{
  int			i = 4;
  std::string		tmp;
  std::string		tmp2;
  std::stringstream	value;
  int			i_value;

  if ((ac - i) % 2 != 0)
    throw(MyException("Option unknown"));
  while(i + 1 < ac)
    {
      tmp.assign(av[i]);
      if (_ident.find(av[i]) != _ident.end())
	{
	  tmp2.assign(av[i + 1]);
	  for (int j = 0; tmp2[j]; ++j)
	    {
	      std::cout << tmp2[j] << std::endl;
	      if (tmp2[j] < '0' || tmp2[j] > '9')
		throw(MyException("Option unknown"));
	    }
	  value << av[i + 1];
	  value >> i_value;
	  _options[_ident.find(av[i])->second] = i_value;
	}
      value.clear();
      i += 2;
    }
}

void		Options::setOption(e_options option, int value)
{
  this->_options[option] = value;
}

int		Options::getOption(e_options option) const
{
  return (this->_options[option]);
}
