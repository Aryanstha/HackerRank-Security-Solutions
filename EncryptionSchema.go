package main

import "fmt"

func factorial(n int) int {
	if n == 1 {
		return n
	}
	return factorial(n-1) * n
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	fmt.Println(factorial(n))
}
