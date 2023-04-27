fn main() {
    loop {
        let x = vec![0; 1000];
        drop(x);
    }
}
