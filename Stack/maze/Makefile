.SUFFIXES : .c .o

TARGET = maze
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

OBJS = doublylist.o maze.o maze_solver.o
SRCS = $(OBJS.o=.c)

all : $(TARGET)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@
