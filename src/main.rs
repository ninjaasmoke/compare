fn main() {
    run();
}

fn run() {
    let mut output = String::with_capacity(9_000_000);
    for i in 1..=1000000 {
        match (i % 3, i % 5) {
            (0, 0) => output.push_str("FizzBuzz\n"),
            (0, _) => output.push_str("Fizz\n"),
            (_, 0) => output.push_str("Buzz\n"),
            _ => output.push_str(&i.to_string()),
        }
    }
    print!("{}", output);
}
