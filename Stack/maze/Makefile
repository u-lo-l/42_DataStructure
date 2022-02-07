.SUFFIXES : .c .o

TARGET = maze.out
CC = gcc
CFLAGS = -Wall -Wextra
RM = rm -f

OBJS = linkedlist.o linkedstack.o maze_create.o maze_solver.o
SRCS = $(OBJS.o=.c)

all : $(TARGET)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re

$(TARGET) : $(OBJS)
	$(CC) -g -o $(TARGET) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@
