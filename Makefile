NAME		= g_engine

RM		= rm -f

CC		= g++

CXXFLAGS	= -W -Wall -Wextra

SDL_FLAGS	= -lSDL
NCURSES_FLAGS	= -lncurses
OPENGL_FLAGS	= -lGL -lGLU

LUALIB		= /usr/include/lua-5.3.2/src/liblua.a

LIB_FLAGS	= $(SDL_FLAGS) $(NCURSES_FLAGS) $(OPENGL_FLAGS) -ldl $(LUALIB)

OPENGL_NAME	= openGL/lib_nibbler_opengl.so
NCURSES_NAME	= ncurse/lib_nibbler_ncurses.so
SDL_NAME	= SDL/lib_nibbler_SDL.so

SRC		= src/main.cpp\
		src/core/Core.cpp\
		src/images/Texture.cpp\
		src/sweet/SweetFactory.cpp\
		src/sweet/Sweet.cpp\
		src/sweet/NormalSweet.cpp\
		src/sweet/SpeedSweet.cpp\
		src/Options.cpp\
		src/Map.cpp\
		src/Snake.cpp\
		src/MyException.cpp

OPENGL_SRC	= openGL/Functions.cpp\
		openGL/CoreLibrary.cpp\
		openGL/Graph.cpp

NCURSES_SRC	= ncurse/Functions.cpp\
		ncurse/CoreLibrary.cpp

SDL_SRC		= SDL/Functions.cpp\
		SDL/CoreLibrary.cpp

OBJ_SRC		= $(SRC:.cpp=.o)
OBJ_OPENGL	= $(OPENGL_SRC:.cpp=.o)
OBJ_NCURSES	= $(NCURSES_SRC:.cpp=.o)
OBJ_SDL		= $(SDL_SRC:.cpp=.o)
OBJS		+= $(OBJ_SRC) $(OBJ_OPENGL) $(OBJ_NCURSES) $(OBJ_SDL)


all		:	$(NAME);

$(NAME)		:	$(OBJS)
		$(CC) -g -fPIC $(OBJ_SRC) -o $(NAME) $(LIB_FLAGS) $(CXXFLAGS)
		$(CC) -g -shared -fPIC $(OBJ_OPENGL) -o $(OPENGL_NAME) $(OPENGL_FLAGS) $(SDL_FLAGS)
		$(CC) -g -shared -fPIC $(OBJ_NCURSES) -o $(NCURSES_NAME) $(NCURSES_FLAGS)
		$(CC) -g -shared -fPIC $(OBJ_SDL) -o $(SDL_NAME) $(SDL_FLAGS)

.cpp.o		:
		$(CC) $(CXXFLAGS) -fPIC -c $< -o $@

clean		:
		$(RM) $(OBJ_SRC)
		$(RM) $(OBJ_OPENGL)
		$(RM) $(OBJ_NCURSES)
		$(RM) $(OBJ_SDL)

fclean		:	clean
		$(RM) $(NAME)
		$(RM) $(OPENGL_NAME)
		$(RM) $(NCURSES_NAME)
		$(RM) $(SDL_NAME)

make re		:	fclean all

.PHONY		:	make re all clean fclean src
