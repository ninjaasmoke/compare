package main

import (
	"os"
	"strconv"
	"strings"
)

func main() {
	run()
}

func run() {
	var b strings.Builder
	for i := 1; i <= 10000000; i++ {
		switch {
		case i%15 == 0:
			b.WriteString("FizzBuzz\n")
		case i%3 == 0:
			b.WriteString("Fizz\n")
		case i%5 == 0:
			b.WriteString("Buzz\n")
		default:
			b.WriteString(strconv.Itoa(i))
			b.WriteByte('\n')
		}
	}
	os.Stdout.WriteString(b.String())
}
