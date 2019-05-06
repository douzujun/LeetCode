#include <iostream>
#include <stack>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void PrintListReversingly(ListNode* head) {
        stack<ListNode*> nodes;
        
        ListNode *pNode = head;
        while (pNode != nullptr)
        {
        	nodes.push(pNode);
        	pNode = pNode->next;
		}
		
		while (!nodes.empty())
		{
			pNode = nodes.top();
			cout << pNode->val << "\t";
			nodes.pop();	
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
        p->next = NULL;
        
        head = head->next;
		s.PrintListReversingly(head);
}
int main()
{
    test_data();
    return 0;
    
}
