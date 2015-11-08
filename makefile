# makefile for TSS estimator

./bin/main: ./src/main.c ./src/get_input.c
	gcc ./src/main.c ./src/get_input.c -o ./bin/main
