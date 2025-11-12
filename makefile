CC = gcc
CFLAGS = -Wall -Wextra -g
SRCS = ctwixt.c link.c board.c logic.c
OBJS = $(SRCS:.c=.o)
TARGET = twixt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)