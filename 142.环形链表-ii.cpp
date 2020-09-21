/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        ListNode *fast = head, *slow = head;
        while (true)
        {
            if (!(fast && fast->next)) {
                return nullptr;
            }
            slow = slow->next; 
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
        
    }
};
// @lc code=end

