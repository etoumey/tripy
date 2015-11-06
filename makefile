# makefile for TSS estimator

./bin/main: ./src/main.c
	gcc ./src/main.c -o ./bin/main
