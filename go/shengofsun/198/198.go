package main

import "fmt"

func Max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}

func rob(nums []int) int {
	if len(nums) <= 0 {
		return 0
	}
	first := 0
	second := nums[0]
	for i:=1; i<len(nums); i++ {
		first, second = second, Max(first+nums[i], second)
	}
	return second
}

func main() {
	nums := []int{2, 7, 1, 3, 4}
	fmt.Println(rob(nums))
}
