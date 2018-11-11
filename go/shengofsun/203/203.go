package main

import "github.com/shengofsun/utils"

type ListNode = utils.ListNode

func removeElements(head *ListNode, val int) *ListNode {
	fake_head := ListNode{0, nil}
	tail := &fake_head
	for head!=nil {
		if head.Val!=val {
			tail.Next = head
			tail = head
		}
		head = head.Next
	}
	tail.Next = nil
	return fake_head.Next
}

func main() {
	inputs := []int{1, 2, 6, 3, 4, 5, 6}
	l := utils.CreateListNode(inputs)
	result := removeElements(l, 1)
	result.Print()
}
