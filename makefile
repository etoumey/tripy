# makefile for TSS estimator

./bin/main: ./src/main.c ./src/get_input.c ./src/calc_hr_zones.c ./src/file_process.c
	gcc ./src/main.c ./src/get_input.c ./src/calc_hr_zones.c ./src/file_process.c -o ./bin/main -lm
