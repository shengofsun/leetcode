package main

import "fmt"

func Min(a int, b int) int {
	if a<b {
		return a
	}
	return b
}

func Max(a int, b int) int {
	if a<b {
		return b
	}
	return a

}

func rotate(nums []int, k int) {
	if len(nums)<=0 {
		return
	}
	k%=len(nums)

	left := 0
	middle := len(nums) - k
	right := len(nums)

	step := Min(middle-left, right-middle)
	for step>0 {
		for i:=0; i<step; i++ {
			nums[left+i], nums[right-step+i] = nums[right-step+i], nums[left+i]
		}

		if middle-left < right-middle {
			right -= step
		} else {
			left += step
		}

		step = Min(middle-left, right-middle)
	}
}

func PrintArray(nums []int) {
	for i:=0; i<len(nums); i++ {
		fmt.Printf("%d ", nums[i])		
	}
}

func main() {
	input := []int{1, 2, 3, 4, 5, 6, 7}
	rotate(input, 7)
	PrintArray(input)
}
