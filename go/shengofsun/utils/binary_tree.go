package utils

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
