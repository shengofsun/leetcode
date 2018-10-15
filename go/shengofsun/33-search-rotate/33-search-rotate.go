package main

import "fmt"

func binary_search(nums []int, left int, right int, target int) int {
	l := left
	r := right

	for l+1 < r {
		middle := (l+r)/2
		if nums[middle] <= target {
			l = middle
		} else {
			r = middle
		}
	}

	if nums[l] == target {
		return l
	}
	return -1
}

func do_search(nums []int, left int, right int, target int) int {
	if left + 1 >= right {
		if nums[left] == target {
			return left
		}
		return -1
	}

	middle := (left + right)/2
	if nums[middle] <= nums[right - 1] {
		if nums[middle] <= target && nums[right -1] >= target {
			return binary_search(nums, middle, right, target)
		} else {
			return do_search(nums, left, middle, target)
		}
	} else {
		if nums[left] <= target && nums[middle - 1] >= target {
			return binary_search(nums, left, middle, target)
		} else {
			return do_search(nums, middle, right, target)
		}
	}
}

func search(nums []int, target int) int {
	if len(nums) <= 0 {
		return -1
	}
	return do_search(nums, 0, len(nums), target)
}

func main(){
	nums := []int{1, 3, 5}
	fmt.Println(search(nums, 3))
}
