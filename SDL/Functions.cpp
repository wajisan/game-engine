#include "CoreLibrary.hpp"

int		event(int &cur_dir)
{
  return (CoreLibrary::getInstance()->eventLib(cur_dir));
}

int		draw(std::string map, int size_x, int size_y)
{
  return (CoreLibrary::getInstance()->drawLib(map, size_x, size_y));
}

int		setData(int &cur_dir, int size_x, int size_y)
{
  CoreLibrary::getInstance()->setData(cur_dir, size_x, size_y);
  return (0);
}

int		destroy(void)
{
  CoreLibrary::destroyInstance();
  return (0);
}
