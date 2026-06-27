CC = gcc
CFLAGS = -Wall -Wextra

all: test_int inner_demo box3d point.o

test_int: to_test_int.o arithmetic.o
	$(CC) $(CFLAGS) -o $@ $^

inner_demo: inner_class_demo.o
	$(CC) $(CFLAGS) -o $@ $^

box3d: box3d.o box.o
	$(CC) $(CFLAGS) -o $@ $^

point.o: point.c point.h
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: all
	@echo "Running Task 1 (Test/Arithmetic)"
	./test_int
	@echo ""
	@echo "Running Task 2 (InnerClassDemo)"
	./inner_demo
	@echo ""
	@echo "Running Task 4 (Box/Box3d)"
	./box3d
	@echo ""

clean:
	rm -f *.o test_int inner_demo box3d
