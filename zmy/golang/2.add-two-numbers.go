/*
 * @lc app=leetcode id=2 lang=golang
 *
 * [2] Add Two Numbers
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	p := head
	acc := 0
	for l1 != nil || l2 != nil || acc !=0 {
		if l1 != nil {
			acc += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			acc += l2.Val
			l2 = l2.Next
		}
		p.Next = &ListNode{Val: acc % 10, Next: nil}
		acc /= 10
		p = p.Next
	}
	return head.Next
}

