# echo "building programs"
npm run build

# echo "running Python"
# time python3 ./py/index.py > /dev/null
# echo "running C"
# time ./c/run > /dev/null
# echo "running Go"
# time ./go/run > /dev/null
# echo "running RUST"
# time target/release/QuickSort > /dev/null
# echo "running JS"
# time node ./js/index.js > /dev/null

#!/bin/bash

# Compile the C program

# Run the program multiple times and measure execution time
for i in {1..10}; do
    echo "Running test $i..."
    time ./c/run
done
