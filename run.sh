echo "building programs"
npm run build
echo "running node - using memo (array)"
time node index.js > /dev/null
echo "running go - using memo (array)"
time ./gobuild/run > /dev/null
echo "running rust - using memo"
time target/release/speedtest > /dev/null
echo "running C - using memo (array)"
time ./cbuild/run > /dev/null