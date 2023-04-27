use std::fs::File;
use std::io::{Read, Write};
use std::fmt::{Write as FWrite};

const BUFFER_SIZE: usize = 5 * 1024 * 1024;

fn main() {
    let input_path = "data.txt";
    let output_path = "./output/rust.txt";

    let mut file = File::open(input_path).expect("failed to open input file");

    // ensure string buffer is the same as Go.
    let mut string = String::with_capacity(BUFFER_SIZE);

    // instead of verify the UTF-8 correctness of each substring,
    // do it all at once while reading the file.
    file.read_to_string(&mut string)
        .expect("input file cannot be read or is not UTF-8");
        
    let mut numbers: Vec<i32> = string
        .split(",")
        .map(|substr| substr.trim().parse::<i32>().expect("invalid number"))
        .collect();

    quicksort(&mut numbers);
    
    // The size of our output shouldn't change (just be re-ordered)
    // so we'll clear the string we read data in with, and write to it.
    string.clear();
    for number in numbers {
        write!(&mut string, "{} ", number).expect("failed to format a number");
    }
    
    let mut output_file = File::create(output_path).expect("failed to create output file");
    output_file.write_all(string.as_bytes()).expect("filed to write output");
    output_file.sync_all().expect("failed to fsync");
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