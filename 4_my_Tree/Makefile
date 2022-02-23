.SUFFIXES : .c .o

TARGET = binary_tree.out
CC = gcc
RM = rm -f

Q_DIR = ./Queue/
Q_FILES = linkedqueue.o
Q_OBJS = $(addprefix $(Q_DIR), $(Q_FILES))

BT_DIR = ./BinTree/
BT_FILES = bintree.o bintree_traversal.o
BT_OBJS  = $(addprefix $(BT_DIR), $(BT_FILES))

BST_DIR = ./BinSearchTree/
BST_FILES = binsearchtree.o
BST_OBJS = $(addprefix $(BST_DIR), $(BST_FILES))

AVL_DIR = ./AVLTree/
AVL_FILES = avl_tree.o
AVL_OBJS = $(addprefix $(AVL_DIR), $(AVL_FILES))
# RB_DIR = ./RedBlackTree

OBJS = BinaryTreeTest.o \
		$(Q_OBJS) \
		$(BT_OBJS) \
		$(BST_OBJS) \
		$(AVL_OBJS)

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
