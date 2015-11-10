# makefile for TSS estimator

./bin/main: ./src/main.c ./src/get_input.c ./src/calc_hr_zones.c 
	gcc ./src/main.c ./src/get_input.c ./src/calc_hr_zones.c -o ./bin/main -lm
