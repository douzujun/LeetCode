#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
	
	   ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
       dummy -> next = head;
       for (int i = 0; i < m - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
       return dummy -> next;
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
        s.reverseBetween(head, 2, 4);
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


