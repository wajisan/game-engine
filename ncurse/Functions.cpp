#include "CoreLibrary.hpp"

int		event(int &cur_dir)
{
  return (CoreLibrary::getInstance()->eventLib(cur_dir));
}

int		draw(std::string map, int size_x, int size_y)
{
  return (CoreLibrary::getInstance()->drawLib(map, size_x, size_y));
}

int		destroy(void)
{
  CoreLibrary::destroyInstance();
  return (0);
}
