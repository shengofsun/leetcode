package main

import "fmt"

func binary_search(nums []int, left int, right int, target int) bool {
	l := left
	r := right

	for l<r {
		middle := (l+r)/2
		if nums[middle] >= target {
			r = middle
		} else {
			l = middle+1
		}
	}
	return nums[l] == target
}

func do_search(nums []int, left int, right int, target int) bool {
	if (right - left < 2 ) {
		for i:=left; i<=right; i++ {
			if nums[i] == target {
				return true
			}
		}
		return false
	}

	middle:=(left + right)/2
	if nums[middle] == target {
		return true
	}

	if nums[left] > nums[middle] {
		if nums[middle+1] <= target && target<=nums[right] {
			return binary_search(nums, middle+1, right, target)
		}
		return do_search(nums, left, middle-1, target)
	} else if nums[middle] > nums[right] {
		if nums[left] <= target && target<=nums[middle-1] {
			return binary_search(nums, left, middle-1, target)
		}
		return do_search(nums, middle+1, right, target)
	} else {
		ans := do_search(nums, left, middle-1, target) || do_search(nums, middle+1, right, target)
		return ans
	}
}

func search(nums []int, target int) bool {
	return do_search(nums, 0, len(nums)-1, target)
}

func main() {
	nums := []int{4, 5, 6, 7, 0, 1, 2}
	fmt.Println(search(nums, 4))
	fmt.Println(search(nums, 7))
}
