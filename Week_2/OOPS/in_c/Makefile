CC = gcc
CFLAGS = -Wall -Wextra -I.
SRCS = music/string/veena.c music/wind/saxophone.c live/test.c
OUT = test

all: $(OUT)

$(OUT): $(SRCS)
	$(CC) $(CFLAGS) -o $(OUT) $(SRCS)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
