echo "building programs"
npm run build

echo "running Python"
time python3 ./python/init.py > /dev/null
echo "running C"
time ./c/run > /dev/null
echo "running Go"
time ./go/run > /dev/null
echo "running RUST"
time target/release/QuickSort > /dev/null