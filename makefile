# makefile for TSS estimator

./bin/main: ./bin/main.o ./bin/get_input.o ./bin/calc_hr_zones.o
	gcc ./bin/main.o ./bin/get_input.o ./bin/calc_hr_zones.o -o ./bin/main -lm

./bin/main.o: ./src/main.c
	gcc ./src/main.c -o main.o

./bin/get_input.o: ./src/get_input.c
	gcc ./src/get_input.c -o get_input.o

./bin/calc_hr_zones.o: ./src/calc_hr_zones.c
	gcc ./src/calc_hr_zones.c -o calc_hr_zones.o
