NAME	= lib_nibbler_ncurses.so

CC	= g++

RM	= rm -f

CPPFLAGS = -W -Wall -Werror

SRC	= Functions.cpp\
	CoreLibrary.cpp\

OBJS	= $(SRC:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -shared -fPIC -W -Wall -Werror $(OBJS) -o $(NAME)

.cpp.o	:	
	$(CC) -fPIC -lncurses -c $<

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	make re all clean fclean
