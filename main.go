package main

import "fmt"

func main() {
	run()
}

func memoize(f func(int) string) func(int) string {
	cache := make([]string, 10000000)
	return func(n int) string {
		if cache[n-1] != "" {
			return cache[n-1]
		}
		res := f(n)
		cache[n-1] = res
		return res
	}
}

func fizzbuzz(n int) string {
	switch {
	case n%3 == 0 && n%5 == 0:
		return "FizzBuzz"
	case n%3 == 0:
		return "Fizz"
	case n%5 == 0:
		return "Buzz"
	default:
		return fmt.Sprintf("%d", n)
	}
}

func run() {
	f := memoize(fizzbuzz)

	var fizzBuzzNumbers []string
	for i := 1; i <= 10000000; i++ {
		fizzBuzzNumbers = append(fizzBuzzNumbers, f(i))
	}

	// fmt.Println("FizzBuzz sequence:", fizzBuzzNumbers)
}
