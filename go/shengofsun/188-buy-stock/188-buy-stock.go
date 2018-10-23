package main

import "fmt"

func Max(a int, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func Min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func Create2DArray(row int, col int) [][]int {
	ans := make([][]int, row)
	for i:=0; i<row; i++ {
		ans[i] = make([]int, col)
		for j:=0; j<col; j++ {
			ans[i][j] = 0
		}
	}
	return ans
}

// total[i][j] = max(total[i-1][j], last[i][j])
// last[i][j] = max(last[i-1][j] + price[i]-price[i-1], total[i-1][j-1]+max(price[i]-price[i-1], 0))
func maxProfit(k int, prices []int) int {
	if len(prices) < 2 {
		return 0
	}
	
	if k > len(prices)-1 {
		k = len(prices)-1
	}

	total := Create2DArray(2, k+1)
	last := Create2DArray(2, k+1)
	prev := 0
	current := 1
	
	for i:=1; i<len(prices); i++ {
		profit := prices[i] - prices[i-1]
		for j:=1; j<=Min(i, k); j++ {
			last[current][j] = Max(last[prev][j] + profit, total[prev][j-1]+Max(profit, 0))
			total[current][j] = Max(total[prev][j], last[current][j])
		}
		tmp := prev
		prev = current
		current = tmp
	}
	return total[prev][k]
}

func main() {
	prices := []int{3, 3, 5, 0, 0, 3, 1, 4}
	fmt.Println(maxProfit(2, prices))

	p1 := []int{2, 4, 1}
	fmt.Println(maxProfit(2, p1))

	p2 := []int{3, 2, 6, 5, 0, 3}
	fmt.Println(maxProfit(2, p2))
}
