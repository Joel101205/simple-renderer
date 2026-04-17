CC = gcc
CFLAGS = -Wall -Wextra -std=c17

TARGET = renderer
SRCS = main.c renderer.c obj_parser.c matrix.c vector.c
OBJS = $(SRCS:.c=.o)

SDL2 = -lSDL2
MATH = -lm

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(SDL2) $(MATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
