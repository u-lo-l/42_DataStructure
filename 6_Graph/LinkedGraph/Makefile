.SUFFIXES : .c .o

TARGET = Test
CC = gcc -g3 -fsanitize=address
RM = rm -f

STACK_DIR = ./Stack/
STACK_FILES = linkedstack.o
STACK_OBJS = $(addprefix $(STACK_DIR), $(STACK_FILES))

QUEUE_DIR = ./Queue/
QUEUE_FILES = linkedqueue.o
QUEUE_OBJS = $(addprefix $(QUEUE_DIR), $(QUEUE_FILES))

HEAP_DIR = ./MinHeap/
HEAP_FILES = minheap.o
HEAP_OBJS = $(addprefix $(HEAP_DIR), $(HEAP_FILES))

LST_DIR = ./LinkedList/
LST_FILES = linkedlist.o
LST_OBJS  = $(addprefix $(LST_DIR), $(LST_FILES))

GRAPH_DIR = ./
GRAPH_FILES = linkedgraph.o linkedgraph_test.o unionfind.o graph_traversal.o
GRAPH_OBJS = $(addprefix $(GRAPH_DIR), $(GRAPH_FILES))

# KRUSKAL_DIR = ./MinSpanningTree/Kruskal/
# KRUSKAL_FILES = kruskal.o
# KRUSKAL_OBJS = $(addprefix $(KRUSKAL_DIR), $(KRUSKAL_FILES))

# PRIM_DIR = ./MinSpanningTree/Prim/
# PRIM_FIELS = prim.o
# PRIM_OBJS = $(addprefix $(PRIM_DIR), $(PRIM_FIELS))

MST_DIR = ./MinSpanningTree/
MST_FILES = kruskal.o prim.o
MST_OBJS = $(addprefix $(MST_DIR), $(MST_FILES))

OBJS =	$(GRAPH_OBJS) \
		$(HEAP_OBJS) \
		$(STACK_OBJS) \
		$(QUEUE_OBJS) \
		$(LST_OBJS) \
		$(MST_OBJS)

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

