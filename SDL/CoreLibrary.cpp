#include "CoreLibrary.hpp"

CoreLibrary	*CoreLibrary::instance = NULL;

CoreLibrary::CoreLibrary(void)
{
  this->initLib();
}

CoreLibrary::~CoreLibrary(void)
{
  this->destroyLib();
}

void			CoreLibrary::initLib(void)
{
  this->screen = NULL;
  this->fond = NULL;
  this->body = NULL;
  this->fruit = NULL;
  this->head = NULL;
  this->sweet = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    exit(EXIT_FAILURE);
  this->screen = SDL_SetVideoMode(40 * 30, 40 * 30, 32, SDL_HWSURFACE);
  if (this->screen == NULL)
    exit(EXIT_FAILURE);
  SDL_WM_SetCaption("Nibbler", NULL);
  this->loadLib();
}

int			CoreLibrary::setData(int &cur_dir, int map_x, int map_y)
{
  this->cur_dir = cur_dir;
  this->map_x = map_x;
  this->map_y = map_y;
  return (0);
}

void			CoreLibrary::destroyLib(void)
{


}

CoreLibrary		*CoreLibrary::getInstance(void)
{
  if (instance == NULL)
    instance = new CoreLibrary();
  return (instance);
}

void                    CoreLibrary::destroyInstance(void)
{
  if (instance)
    delete instance;
  instance = NULL;
}


int			CoreLibrary::loadLib(void)
{
  this->fond = SDL_LoadBMP("./SDL/img/fond.bmp");
  this->body = SDL_LoadBMP("./SDL/img/body.bmp");
  this->sweet = SDL_LoadBMP("./SDL/img/sweet.bmp");
  this->head = SDL_LoadBMP("./SDL/img/head.bmp");
  this->fruit = SDL_LoadBMP("./SDL/img/fruit.bmp");
  if (this->fond == NULL)
    {
      this->fond = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 30, 32, 0, 0, 0, 0);
      SDL_FillRect(this->fond, NULL, SDL_MapRGB(this->fond->format, 17, 206, 112));
    }
  if(this->body == NULL)
    {
      this->body = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 30, 32, 0, 0, 0, 0);
      SDL_FillRect(this->body, NULL, SDL_MapRGB(this->body->format, 150, 150, 150));
    }
  if(this->fruit == NULL)
    {
      this->fruit = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 30, 32, 0, 0, 0, 0);
      SDL_FillRect(this->fruit, NULL, SDL_MapRGB(this->fruit->format, 150, 150, 150));
    }
  if (this->head == NULL)
    {
      this->head = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 30, 32, 0, 0, 0, 0);
      SDL_FillRect(this->head, NULL, SDL_MapRGB(this->fond->format, 150, 150, 150));
    }
  if (this->sweet == NULL)
    {
      this->sweet = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 30, 32, 0, 0, 0, 0);
      SDL_FillRect(this->sweet, NULL, SDL_MapRGB(this->fond->format, 150, 150, 150));
    }
  return (0);
}

int			CoreLibrary::unloadLib(void)
{
  SDL_FreeSurface(this->screen);
  SDL_FreeSurface(this->fond);
  SDL_FreeSurface(this->body);
  SDL_FreeSurface(this->fruit);
  SDL_FreeSurface(this->head);
  SDL_FreeSurface(this->sweet);
  SDL_Quit();
  return (0);
}

int			CoreLibrary::eventLib(int &cur_dir)
{
  SDL_Event		event;
  
  while (SDL_PollEvent(&event))
    {    
      if (event.type == SDL_QUIT)
	return (1);
      if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    return (1);
	  if (event.key.keysym.sym == SDLK_LEFT)
	    cur_dir = cur_dir + 1 > 3 ? 0 : cur_dir + 1;
	  else if (event.key.keysym.sym == SDLK_RIGHT)
	    cur_dir = cur_dir - 1 < 0 ? 3 : cur_dir - 1;
	  return (0);
	}
    }
      // Fonction pour gerer les touches
  return (0);
}

int			CoreLibrary::drawLib(std::string map, int size_x, int size_y)
{
  int		i;

  i = 0;
  this->pos.y = 0;
  this->pos.x = 0;
  while (i <  size_x * size_y)
    {
      if (map[i] == '.')
	{
	  SDL_BlitSurface(this->fond, NULL, this->screen, &this->pos);
	  this->pos.x = this->pos.x + 30;
	  i++;
	}
      else if (map[i] == 'o')
	{
	  SDL_BlitSurface(this->body, NULL, this->screen, &this->pos);
	  this->pos.x = this->pos.x + 30;
	  i++;
	}
      else if (map[i] == 'H')
        {
          SDL_BlitSurface(this->head, NULL, this->screen, &this->pos);
          this->pos.x = this->pos.x + 30;
          i++;
        }
      else if (map[i] == 's') 
	{
	  SDL_BlitSurface(this->sweet, NULL, this->screen, &this->pos);
	  this->pos.x = this->pos.x + 30;
	  i++;
	}
      else if (map[i] == 'f')
	{
	  SDL_BlitSurface(this->fruit, NULL, this->screen, &this->pos);
	  this->pos.x = this->pos.x + 30;
          i++; 
	}
      if (i % size_x == 0)
        {
          this->pos.y = this->pos.y + 30;
          this->pos.x = 0;
        }
    }
  SDL_Flip(this->screen);
  return (0);
}
