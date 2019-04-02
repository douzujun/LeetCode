#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next) return head;
        //get middle node
        //not right if write: *fast = head. Otherwise, {2, 1} will not be sorted.
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *left = head, *right = slow->next;
        slow->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return Merge(left, right);
    }

    ListNode *Merge(ListNode *Left, ListNode *Right) {

        if (!Left) return Right;
        if (!Right) return Left;
        ListNode *h = NULL;
        if (Left->val < Right->val) {
            h = Left;
            h->next = Merge(Left->next, Right);
        }
        else {
            h = Right;
            h->next = Merge(Left, Right->next);
        }

        return h;
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
    //-1 5 3 4 0
    while (T-- && cin >> n)
    {
        ListNode *q;
        q = new ListNode(n);
        p->next = q;
        p = q;
    }

    head = head->next;
    s.sortList(head);

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
