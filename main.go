// package main

// import (
// 	"fmt"
// 	"time"
// )

// func main() {
// 	start := time.Now()

// 	memo := make(map[int]string)

// 	isDivisibleBy := func(n int) func(x int) bool {
// 		return func(x int) bool { return x%n == 0 }
// 	}

// 	fizzBuzz := func(n int) string {
// 		result := ""
// 		if isDivisibleBy(3)(n) {
// 			result += "Fizz"
// 		}
// 		if isDivisibleBy(5)(n) {
// 			result += "Buzz"
// 		}
// 		if result == "" {
// 			result = fmt.Sprintf("%d", n)
// 		}
// 		return result
// 	}

// 	fizzBuzzMemo := func(n int) string {
// 		if val, ok := memo[n]; ok {
// 			return val
// 		}
// 		result := fizzBuzz(n)
// 		memo[n] = result
// 		return result
// 	}

// 	var fizzBuzzNumbers []string
// 	for i := 1; i <= 100000; i++ {
// 		fizzBuzzNumbers = append(fizzBuzzNumbers, fizzBuzzMemo(i))
// 	}

// 	fmt.Println(fizzBuzzNumbers)

// 	end := time.Now()
// 	fmt.Printf("Execution time: %v\n", end.Sub(start))
// }
