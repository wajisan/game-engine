#include "CoreLibrary.hpp"

CoreLibrary	*CoreLibrary::instance = NULL;

CoreLibrary::CoreLibrary(void)
{
}

CoreLibrary::~CoreLibrary(void)
{
}

void			CoreLibrary::initLib(void)
{
  // Initialisation de la fenetre lib
}

void			CoreLibrary::destroyLib(void)
{
  // fermeture de la lib
}

CoreLibrary		*CoreLibrary::getInstance(void)
{
  if (!(instance))
    return (new CoreLibrary());
  else
    return (instance);
}

int			CoreLibrary::loadLib(void)
{
  // Chargement de toutes les images, textures
}

int			CoreLibrary::unloadLib(void)
{
  // Free de toutes les images, textures
}

int			CoreLibrary::eventLib(int &cur_dir)
{
  // Fonction pour gerer les touches
}

int			CoreLibrary::drawLib(void *map)
{
  // Fonction pour dessiner la map
}
