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
