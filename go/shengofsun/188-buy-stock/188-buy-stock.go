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

// total[i][j] = max(total[i-1][j], last[i][j])
// last[i][j] = max(last[i-1][j] + price[i]-price[i-1], total[i-1][j-1]+max(price[i]-price[i-1], 0))
func maxProfit(k int, prices []int) int {
	days := len(prices)
	if k > days {
		k = days
	}

	total := make([]int, k+1)
	last := make([]int, k+1)

	total[0] = 0
	last[0] = 0

	for i := 1; i < days; i++ {
		profit := prices[i] - prices[i-1]
		for j := Min(i, k); j > 0; j-- {
			if j >= i {
				last[j] = total[j-1] + Max(profit, 0)
				total[j] = last[j]
			} else {
				last[j] = Max(last[j]+profit, total[j-1]+Max(profit, 0))
				total[j] = Max(total[j], last[j])
			}
		}
	}

	return total[k]
}

func main() {
	prices := []int{3, 3, 5, 0, 0, 3, 1, 4}
	fmt.Println(maxProfit(2, prices))
}
