package main

import "fmt"

// ABC
// m(1) * 26^2 + m(2) * 26 + m(n)
func convertToTitle(n int) string {
	result := []byte{}
	for n > 0 {
		result = append(result, (byte)('A'+(n-1)%26))
		n = (n-1)/26
	}

	i:=0
	j:=len(result)-1

	for i<j {
		t := result[i]
		result[i] = result[j]
		result[j] = t
		i++
		j--
	}

	return string(result)
}

func main() {
	nums := []int{1, 28, 701}
	for i:=0; i<len(nums); i++ {
		fmt.Println(convertToTitle(nums[i]))
	}
}