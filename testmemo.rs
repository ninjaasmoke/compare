use std::collections::HashMap;
use std::time::Instant;

fn memoize<F, T, U>(mut f: F) -> impl FnMut(T) -> U
where
    F: FnMut(T) -> U,
    T: Copy + Eq + std::hash::Hash,
    U: Copy,
{
    let mut cache = HashMap::new();
    move |arg| {
        if let Some(&val) = cache.get(&arg) {
            val
        } else {
            let val = f(arg);
            cache.insert(arg, val);
            val
        }
    }
}

fn fizzbuzz(n: u32) -> &'static str {
    match (n % 3, n % 5) {
        (0, 0) => "FizzBuzz",
        (0, _) => "Fizz",
        (_, 0) => "Buzz",
        _ => "",
    }
}

fn main() {
    let start = Instant::now();

    let mut f = memoize(fizzbuzz);

    let _values: Vec<_> = (1..=100000).map(|i| f(i)).collect();

    println!("Elapsed time: {:?}", start.elapsed());
}
