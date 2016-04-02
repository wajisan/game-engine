#include "CoreLibrary.hpp"

int		event(int &cur_dir)
{
  CoreLibrary::getInstance()->eventLib(cur_dir);
}

int		draw(void *map)
{
  CoreLibrary::getInstance()->drawLib(map);
}
