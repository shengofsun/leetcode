package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func (node *TreeNode) Add(value int) {
	if value < node.Val {
		if node.Left == nil {
			node.Left = &TreeNode{value, nil, nil}
		} else {
			node.Left.Add(value)
		}
	} else if value > node.Val {
		if node.Right == nil {
			node.Right = &TreeNode{value, nil, nil}
		} else {
			node.Right.Add(value)
		}
	}
}

type Stack struct {
	vals []*TreeNode
	pos int
}

func createStack() *Stack {
	return &Stack{make([]*TreeNode, 10), -1}
}

func (s *Stack) Push(item *TreeNode){
	s.pos++
	if len(s.vals) > s.pos {
		s.vals[s.pos] = item
	} else {
		s.vals = append(s.vals, item)
	}
}

func (s *Stack) Pop() *TreeNode {
	result := s.vals[s.pos]
	s.pos--
	return result
}

func (s *Stack) Peek() *TreeNode {
	return s.vals[s.pos]
}

func (s *Stack) Len() int {
	return s.pos+1
}

type TreeIter struct {
	node_stack *Stack
	left_to_right bool
}

func create(node *TreeNode, is_left_to_right bool) *TreeIter {
	result := &TreeIter{createStack(), is_left_to_right}
	current := node
	if is_left_to_right {
		for current != nil {
			result.node_stack.Push(current)
			current = current.Left
		}
	} else {
		for current != nil {
			result.node_stack.Push(current)
			current = current.Right
		}
	}
	return result
}

func (iter *TreeIter) current() *TreeNode {
	if iter.node_stack.Len() > 0 {
		return iter.node_stack.Peek()
	}
	return nil
}

func (iter *TreeIter) next() {
	if iter.node_stack.Len() != 0 {
		current := iter.node_stack.Pop()
		if iter.left_to_right {
			current = current.Right
			for current != nil {
				iter.node_stack.Push(current)
				current = current.Left
			}
		} else {
			current = current.Left
			for current != nil {
				iter.node_stack.Push(current)
				current = current.Right
			}
		}
	}
}

func findTarget(root *TreeNode, k int) bool {
	if root == nil {
		return false
	}

	left_iter := create(root, true)
	right_iter := create(root, false)

	for {
		l := left_iter.current()
		r := right_iter.current()
		if l == r {
			return false
		}

		ans := l.Val+r.Val
		if ans == k{
			return true
		} else if ans < k {
			left_iter.next()
		} else {
			right_iter.next()
		}
	}
}

func main() {
	root := &TreeNode{5, nil, nil}
	root.Add(3)
	root.Add(2)
	root.Add(4)
	root.Add(6)
	root.Add(7)

	left_iter := create(root, true)
	right_iter := create(root, false)
	for left_iter.current() != nil {
		fmt.Println(left_iter.current().Val)
		left_iter.next()
	}

	for right_iter.current() != nil {
		fmt.Println(right_iter.current().Val)
		right_iter.next()
	}
}
