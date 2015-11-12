#!/bin/bash

cd /media/etoumey/GARMIN/Garmin/Activities

FILE=$(ls -t | head -n1)
printf "$FILE"

FILE="TestGPX.gpx"

#gcc ~/Documents/tss_estimator/src/get_input.c ~/Documents/tss_estimator/src/calc_hr_zones.c ~/Documents/tss_estimator/src/main.c -lm -o ~/Documents/tss_estimator/a.out

#./a.out < $FILE
