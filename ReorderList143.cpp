#include <iostream>

using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        //将链表分为前后两部分(使用fast和slow两个指针), 然后将后面的链表进行翻转,这样就可以按
        //顺序将两个链表合并。(1. 链表翻转 2. 链表合并 3. 拆分两个链表)题目的结合.
        if (head == NULL || head->next == NULL || head->next == NULL) {
            return;
        }

        ListNode *slow = NULL, *fast = head->next;
        while (fast && fast->next)
        {
            slow = fast;
            fast = fast->next;
        }

        slow->next = NULL;
        ListNode *next = head->next;
        //翻转链表
        reorderList(next);

        //链表合并  
        head->next = fast;
        fast->next = next;
        
    }

    //非递归
    void reorderList_noRecive(ListNode *head)
    {

        if (head == NULL || head->next == NULL || head->next == NULL) {
            return;
        }

        ListNode *slow = head, *fast = head->next, *second = NULL;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        second = slow->next;
        slow->next = NULL;
        //将后面链表翻转
        ListNode *pre = NULL, *next = NULL;
        while (second != NULL)
        {
            next = second->next;  //存储第一条链表上下一个节点
            //头插法，生成一条新链表
            second->next = pre;   
            pre = second;
            second = next;
        }

        //将两个链表合并, 把第二个链表的每个元素插在第一个链表的后面
        fast = head;
        while (pre != NULL)
        {   
            next = pre;         // next保持新链表pre的当前节点
            pre = pre->next;   
            next->next = fast->next;
            fast->next = next;
            fast = fast->next->next;
        }

    }


};

void test_data()
{
        ListNode *head = new ListNode(0);
        ListNode *p ;
        p = head;
        Solution s;
        int n = 0;
        int T = 5;

        while (T-- && cin >> n)
        {
            ListNode *q;
            q = new ListNode(n);
            p->next = q;
            p = q;
                                                
        }

        head = head->next;
        s.reorderList(head);
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
                                
        }

}


void test_data1()
{
        ListNode *head = new ListNode(0);
        ListNode *p ;
        p = head;
        Solution s;
        int n = 0;
        int T = 5;

        while (T-- && cin >> n)
        {
            ListNode *q;
            q = new ListNode(n);
            p->next = q;
            p = q;
                                                
        }

        head = head->next;
        s.reorderList_noRecive(head);
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
                                
        }

}

int main()
{

    test_data();
    
    test_data1();

    return 0;
}





