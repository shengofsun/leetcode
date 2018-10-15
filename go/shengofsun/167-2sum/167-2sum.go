package main

import "fmt"

func twoSum(numbers []int, target int) []int {
	i:=0
	j:=len(numbers)-1
	for i<j {
		ans := numbers[i] + numbers[j]
		if ans < target {
			i++
		} else if ans > target {
			j--
		} else {
			return []int{i+1, j+1}
		}
	}
	return []int{0, 0}
}

func main() {
	num:=[]int{2,7,11,15}
	fmt.Println(twoSum(num, 9))
}
