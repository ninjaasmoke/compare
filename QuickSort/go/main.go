package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	file, err := os.Open("data.txt")
	if err != nil {
		fmt.Println("Error reading file:", err)
		return
	}
	defer file.Close()

	var arr []int
	const bufferSize = 5 * 1024 * 1024
	reader := bufio.NewReaderSize(file, bufferSize)
	scanner := bufio.NewScanner(reader)
	const maxTokenSize = 5 * 1024 * 1024
	scanner.Buffer(make([]byte, bufio.MaxScanTokenSize), maxTokenSize)

	for scanner.Scan() {
		line := scanner.Text()
		values := strings.Split(line, ",")
		for _, v := range values {
			num, err := strconv.Atoi(v)
			if err != nil {
				fmt.Println("Error converting string to int:", err)
				return
			}
			arr = append(arr, num)
		}
	}
	if err := scanner.Err(); err != nil {
		fmt.Println("Error reading file:", err)
		return
	}

	quicksort(arr, 0, len(arr)-1)

	output, err := os.Create("./go/output.txt")
	if err != nil {
		fmt.Println("Error creating file:", err)
		return
	}
	defer output.Close()

	writer := bufio.NewWriter(output)
	for _, val := range arr {
		_, err := writer.WriteString(strconv.Itoa(val) + " ")
		if err != nil {
			fmt.Println("Error writing to file:", err)
			return
		}
	}
	writer.Flush()
	fmt.Println("Sorted data written to output.txt")
}

func quicksort(arr []int, low, high int) {
	if low < high {
		pivot := partition(arr, low, high)
		quicksort(arr, low, pivot-1)
		quicksort(arr, pivot+1, high)
	}
}

func partition(arr []int, low, high int) int {
	pivot := arr[high]
	i := low - 1
	for j := low; j < high; j++ {
		if arr[j] <= pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}
