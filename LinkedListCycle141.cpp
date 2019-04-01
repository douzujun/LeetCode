#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head) 
    {
        if (head == NULL) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

void test_data()
{
    ListNode *head = new ListNode(0);
    ListNode *p;

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
    p->next = head;          //设置有环
    if (s.hasCycle(head)) {
        cout << "有环\n";
    }
    else {
        cout << "无环\n";
    }


}


void test_data1()
{
    ListNode *head = new ListNode(0);
    ListNode *p;

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

    head = head->next;        //不设置有环
    if (s.hasCycle(head)) {
        cout << "有环\n";
    }
    else {
        cout << "无环\n";
    }
}

int main()
{
    
    test_data();
    
    test_data1();

    return 0;

}










