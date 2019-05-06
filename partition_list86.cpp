#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
		ListNode *pos = dummy, *p = head, *pre = dummy;
		while (p)
		{
			if (p->val >= x)
			{
				pre = p;
				p = p->next;
			}
			/**
			1 3 4 2 5
			
			*/
			else if (pos != pre) 
			{
				pre->next = p->next;
				p->next = pos->next;
				pos->next = p;
				p = pre->next;
				pos = pos->next;
			}
			else 
			{
				pre = p;
				p = p->next;
				pos = pos->next;
			}
		}
		return dummy->next;
    }
};

void test_data()
{
    ListNode *head = new ListNode(0);
    ListNode *p ;
    p = head;
    Solution s;
    int n = 0;
    int T = 6;
    //-1 5 3 4 0
    while (T-- && cin >> n)
    {
        ListNode *q;
        q = new ListNode(n);
        p->next = q;
        p = q;
    }

    head = head->next;
    head = s.partition(head, 3);

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{

    test_data();

    return 0;

}
