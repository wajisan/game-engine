NAME	= nibbler

CC	= g++

RM	= rm -f

SRC	= main.cpp\
	core/Core.cpp\
	images/Texture.cpp\
	sweet/SweetFactory.cpp\
	sweet/Sweet.cpp\
	sweet/NormalSweet.cpp\
	Map.cpp\
	Snake.cpp\
	MyException.cpp

OBJS	= $(SRC:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -g -fPIC $(OBJS) -o $(NAME) -ldl -lSDL -lGL -lGLU

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	make re all clean fclean
