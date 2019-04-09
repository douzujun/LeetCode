#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0; 
        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        return left > right ? left : right;
    }
};
int main()
{
	TreeNode *head;
	TreeNode *p;
	
	head = new TreeNode(3);
	
	p = new TreeNode(9);
	p->left = NULL;
	p->right = NULL;
	
	head->left = p;
	
	p = new TreeNode(20);
	
	TreeNode *q = new TreeNode(15);
	q->left = NULL; q->right = NULL;
	p->left = q;
	
	q = new TreeNode(7);
	q->left = NULL; q->right = NULL;
	p->right = q;	
	
	head->right = p;
		
	Solution s;
	cout << s.maxDepth(head) << endl;
	
	delete p;
	delete q;
	delete head;
	
	return 0;
}
















