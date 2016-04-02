NAME	= lib_nibbler_opengl.so

CC	= g++

RM	= rm -f

SRC	= Functions.cpp\
	CoreLibrary.cpp\
	Graph.cpp\

OBJS	= $(SRC:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -shared -fPIC $(OBJS) -o $(NAME)

.cpp.o	:
	$(CC) -fPIC -lGL -c $<

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	make re all clean fclean
