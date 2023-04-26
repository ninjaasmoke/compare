package main

import (
	"fmt"
	"time"
)

func memoize(f func(int) string) func(int) string {
	cache := make(map[int]string)
	return func(n int) string {
		if res, ok := cache[n]; ok {
			return res
		}
		res := f(n)
		cache[n] = res
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

func main() {
	start := time.Now()

	f := memoize(fizzbuzz)

	var fizzBuzzNumbers []string
	for i := 1; i <= 100000; i++ {
		fizzBuzzNumbers = append(fizzBuzzNumbers, f(i))
	}

	// fmt.Println("FizzBuzz sequence:", fizzBuzzNumbers)
	fmt.Println("Elapsed time:", time.Since(start))
}
