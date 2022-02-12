.SUFFIXES : .c .o

TARGET = bank_simul.out
CC = gcc
RM = rm -f

OBJS = main.o simlinkeddeque.o simutil.o
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
