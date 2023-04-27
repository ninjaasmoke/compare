use std::fs::File;
use std::io::{BufRead, BufReader, Write};

fn main() {
    let input_path = "data.txt";
    let output_path = "./src/output.txt";

    let file = File::open(input_path).expect("failed to open input file");
    let reader = BufReader::new(file);

    let mut numbers: Vec<i32> = reader
        .split(b',')
        .map(|result| String::from_utf8(result.expect("failed to read line")).expect("invalid UTF-8 string").trim().parse().expect("invalid number"))
        .collect();

    quicksort(&mut numbers);

    let mut file = File::create(output_path).expect("failed to create output file");

    for number in numbers {
        write!(file, "{} ", number).expect("failed to write number to output file");
    }
}

fn quicksort(numbers: &mut [i32]) {
    if numbers.len() <= 1 {
        return;
    }

    let pivot = partition(numbers);

    quicksort(&mut numbers[..pivot]);
    quicksort(&mut numbers[pivot + 1..]);
}

fn partition(numbers: &mut [i32]) -> usize {
    let pivot_index = numbers.len() / 2;
    let pivot = numbers[pivot_index];
    numbers.swap(pivot_index, numbers.len() - 1);

    let mut i = 0;
    for j in 0..numbers.len() - 1 {
        if numbers[j] < pivot {
            numbers.swap(i, j);
            i += 1;
        }
    }

    numbers.swap(i, numbers.len() - 1);
    i
}
