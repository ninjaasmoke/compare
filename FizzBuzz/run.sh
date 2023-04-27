echo "building programs"
npm run build
echo "running rust"
time target/release/speedtest > /dev/null
echo "running go"
time ./gobuild/run > /dev/null
echo "running node"
time node index.js > /dev/null
echo "running C"
time ./cbuild/run > /dev/null
echo "running Java"
time java FizzBuzz > /dev/null
echo "running Python"
time python3 init.py > /dev/null
echo "running C++"
time ./cppbuild/run > /dev/null