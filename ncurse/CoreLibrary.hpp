#ifndef CORELIBRARY_HPP
#define CORELIBRARY_HPP

#include <iostream>
#include <string>
#include "Ncurse.hpp"

class CoreLibrary
{
private:
  CoreLibrary(void);
  ~CoreLibrary(void);
  
  static CoreLibrary	*instance;
  void			*map;

public:
  static CoreLibrary	*getInstance(void);
  static void		destroyInstance(void);

  void			initLib(void);
  void			destroyLib(void);
  int			loadLib(void);
  int			unloadLib(void);
  int			eventLib(int &cur_dir);
  int			drawLib(std::string, int, int);
};

#endif /*! CORELIBRARY_HPP */
