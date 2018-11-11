package main

import "fmt"

func rangeBitwiseAnd(m int, n int) int {
	half_step := 1
	gap := n-m+1
	result := 0
	for half_step>0 && half_step<=n {
		if gap <= half_step {
			b := ((half_step-1)<<1) + 1
			start := (m&b)
			end := (n&b)
			if start>=half_step && start<=end && start>end-half_step {
				result += half_step
			}
		}
		half_step <<= 1
	}
	return result
}

func main() {
	fmt.Println(rangeBitwiseAnd(5, 7))
}
