#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        
        ListNode *cur = head;
        while (cur && cur->next)
        {
        	if (cur->next->val == cur->val)
        	{
        		cur->next = cur->next->next;
			}
			else {
				cur = cur->next;
			}
		}

		return head;
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
        p->next = NULL;
        
        head = head->next;
        head = s.deleteDuplicates(head);
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
