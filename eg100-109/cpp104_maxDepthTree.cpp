
#include<queue>
#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *right;
	TreeNode *left;
	TreeNode(int x):val(x),right(NULL),left(NULL){}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) 
			return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    int maxDepthOrder(TreeNode* root) {
        if (!root) 
        	return 0;
        int res = 0;
        queue<TreeNode*> q;//{{root}};
		q.push(root);
        while (!q.empty()) {
            ++res;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *t = q.front(); 
                q.pop();
                if (t->left) 
                	q.push(t->left);
                if (t->right) 
                	q.push(t->right);
            }
        }
        return res;
    }    
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	TreeNode e(5);
	Solution solve;
	a.left = &b;
	a.right = &c;
	b.left = &d;
	d.right = &e;

	cout << "maxDepth is: " << solve.maxDepth(&a) << endl ;
	cout << "maxDepth is: " << solve.maxDepthOrder(&a) << endl ;

	return 0;
}
