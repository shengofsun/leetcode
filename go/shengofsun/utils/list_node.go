package utils

import "fmt"

type ListNode struct {
	Val int
	Next *ListNode
}

func CreateListNode(numbers []int) *ListNode {
	var tail *ListNode = nil
	for i:=len(numbers)-1; i>=0; i-- {
		current := &ListNode{Val:numbers[i], Next:tail}
		tail = current
	}
	return tail
}

func (l *ListNode) Print() {
	fmt.Print("{")
	first := true
	for l!=nil {
		if !first {
			fmt.Print(",")
		}
		fmt.Print(l.Val)
		first = false
		l = l.Next
	}
	fmt.Print("}\n")
}
