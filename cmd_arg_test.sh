# build the binary
make

# run no arguments, feed first test file and HR
./bin/main <<'EOF' > test_results.txt
TestGPX.gpx
145
EOF
# run no arguments, feed second test file and HR
./bin/main <<'EOF' >> test_results.txt
test2.gpx
145
EOF
# run first test file file, feed HR
./bin/main TestGPX.gpx <<'EOF' >> test_results.txt
145
EOF
# run second test file file, feed HR
./bin/main test2.gpx <<'EOF' >> test_results.txt
145
EOF
# run HR, feed first test file
./bin/main 145 <<'EOF' >> test_results.txt
TestGPX.gpx
EOF
# run first test file, then HR
./bin/main TestGPX.gpx 145 >> test_results.txt
# run HR, then first test file
./bin/main 145 TestGPX.gpx >> test_results.txt
# compare results
diff test_results.txt test_benchmark.txt > test_diff.txt
