TARGET = rbTree.out
CC = gcc
RM = rm -f

Q_DIR = ./Queue/
Q_FILES = linkedqueue.o
Q_OBJS = $(addprefix $(Q_DIR), $(Q_FILES))

RB_DIR = ./RBTree/
RB_FILES = redblacktree.o redblacktree_traversal.o showredblacktree.o
RB_OBJS = $(addprefix $(RB_DIR), $(RB_FILES))

OBJS = redblacktree_test.o \
		$(RB_OBJS) \
		$(Q_OBJS)

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
	$(CC) -c $< -o $@