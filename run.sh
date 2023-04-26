echo "building programs"
npm run build
echo "running rust"
time target/release/speedtest > /dev/null
echo "running go"
time ./gobuild/run > /dev/null
echo "running node"
time node index.js > /dev/null
