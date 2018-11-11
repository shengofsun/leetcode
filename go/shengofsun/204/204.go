package main

import "fmt"

func countPrimes(n int) int {
    if n<=2 {
        return 0
    }

    slots := make([]int, n)
    slots[0] = 1
    slots[1] = 1
    for i:=2; i<n; i++ {
        slots[i] = 0
    }
    for i:=2; i*i<=n; i++ {
        if slots[i]==0 {
            for j:=i*i; j<n; j+=i {
                slots[j]=1
            }
        }
    }

    ans := 0
    for i:=2; i<n; i++ {
        if slots[i]==0 {
            ans++
        }
    }
    return ans
}

func main() {
    fmt.Println(countPrimes(10))
}
