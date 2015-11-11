#!/bin/bash

FILE=$(date +"%Y-%m-%d")
printf "$FILE"

FILE="testGPX.gpx"

gcc ~/Documents/tss_estimator/src/get_input.c ~/Documents/tss_estimator/src/calc_hr_zones.c ~/Documents/tss_estimator/src/main.c -lm -o ~/Documents/tss_estimator/a.out

