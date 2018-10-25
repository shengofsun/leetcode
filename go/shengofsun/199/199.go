package main

import "fmt"

type Node struct {
	data interface{}
	next *Node
}

type Queue struct {
	first Node
	last *Node
}

func createQueue() *Queue {
	ans := &Queue{}
	ans.first.data = nil
	ans.first.next = nil
	ans.last = &ans.first
	return ans
}

func (q *Queue) Enqueue(item interface{}) {
	new_node := &Node{item, nil}
	q.last.next = new_node
	q.last = new_node
}

func (q *Queue) Dequeue() interface{} {
	head := q.first.next
	q.first.next = head.next
	if head == q.last {
		q.last = &q.first
	}
	return head.data
}

func (q *Queue) Empty() bool {
	return &q.first == q.last
}

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
} 

func rightSideView(root *TreeNode) []int {
	ans := make([]int, 0)
	if root==nil {
		return ans
	}

	q := createQueue()
	q.Enqueue(root)
	for !q.Empty() {
		nq := createQueue()
		for !q.Empty() {
			current := q.Dequeue().(*TreeNode)
			if current.Left != nil {
				nq.Enqueue(current.Left)
			}
			if current.Right != nil {
				nq.Enqueue(current.Right)
			}
			if q.Empty() {
				ans = append(ans, current.Val)
			}
		}
		q = nq
	}
	return ans
}

func createTree(vals []int) *TreeNode {
	if len(vals) == 0 {
		return nil
	}
	root := &TreeNode{vals[0], nil, nil}
	q := createQueue()
	q.Enqueue(root)
	index := 1
	for index < len(vals) {
		if !q.Empty() {
			current := q.Dequeue().(*TreeNode)
			if vals[index]!=-1 {
				current.Left = &TreeNode{vals[index], nil, nil}
				q.Enqueue(current.Left)
			}
			index++

			if index < len(vals) && vals[index]!=-1{
				current.Right = &TreeNode{vals[index], nil, nil}
				q.Enqueue(current.Right)
			}
			index++
		}
	}
	return root
}

func main() {
	tree := createTree([]int{1, 2, 3, -1, 5, -1, 4})
	ans := rightSideView(tree)
	fmt.Println(ans)
}
