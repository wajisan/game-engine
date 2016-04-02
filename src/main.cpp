#include "core/Core.hpp"

int		main(int ac, char **av)
{
  //  lua_pushcfunction(L, l_write);
  //lua_setglobal(L, "write"); // this is how function will be named in Lua
  //lua_pcall(L, 0, 0, 0); // run script

  try
    {
      Core		core;
      
      core.load(ac, av, "src/script.lua");
      core.run();
    }
  catch (const Exception &e)
    {
      std::cerr << "Error : " << e.what() << std::endl;
    }
  return (0);
}
