function run() {
  let output = "";
  for (let i = 1; i <= 1000000; ++i) {
    output +=
      i % 15
        ? i % 5
          ? i % 3
            ? i + "\n"
            : "Fizz\n"
          : "Buzz\n"
        : "FizzBuzz\n";
  }
  process.stdout.write(output);
}

run();
