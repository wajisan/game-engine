#include <iostream>
#include <string>

class CoreLibrary
{
private:
  CoreLibrary(void);
  ~CoreLibrary(void);

  static CoreLibrary	*instance;
  void			*map;

public:
  static CoreLibrary	*getInstance(void);

  void			initLib(void);
  void			destroyLib(void);
  int			loadLib(void);
  int			unloadLib(void);
  int			eventLib(int &cur_dir);
  int			drawLib(void *map);
};
