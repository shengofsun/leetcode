package main

import "fmt"

func calcDigitSquareSum(n int) int {
	ans := 0
	for n!=0 {
		ans = ans + (n%10)*(n%10)
		n/=10
	}
	return ans
}

func isHappy(n int) bool {
	slots := make([]int, 1000)
	for i:=0; i<len(slots); i++ {
		slots[i] = 0
	}

	ans := calcDigitSquareSum(n)
	for slots[ans]==0 {
		if ans==1 {
			slots[ans] = 1
		} else {
			slots[ans] = -1
		}
		ans = calcDigitSquareSum(ans)
	}
	return slots[ans]==1
}

func main() {
	fmt.Println(isHappy(8))
}
