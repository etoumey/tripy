# makefile for TSS estimator
SRC_FILES = $(wildcard src/*.c)
OBJ_FILES = $(addprefix bin/,$(notdir $(SRC_FILES:.c=.o)))

./bin/main: $(OBJ_FILES)
	gcc -o $@ $^ -lm

./bin/%.o: src/%.c
	gcc -c -o $@ $< -lm
