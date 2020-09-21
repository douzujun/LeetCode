#
# @lc app=leetcode.cn id=142 lang=python3
#
# [142] 环形链表 II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return None

        fast, slow = head, head
        while True:
            if not (fast and fast.next):
                return None
            slow, fast = slow.next, fast.next.next
            if slow == fast:
                break
        
        fast = head
        while fast != slow:
            slow, fast = slow.next, fast.next

        return fast
        
# @lc code=end

