
#include<stack>
#include<iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
	int hasPathSum(TreeNode *root, int sum){
		if(!root)
			return false;
		
		if(!root->left && !root->right && root->val == sum)
			return true;
		if(root->left)
			return hasPathSum(root->left, sum - root->val);
		if(root->right)
			return hasPathSum(root->right, sum - root->val);
	}
};

class SolutionII {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        stack<TreeNode*> st;//{{root}};
        st.push(root);
        while (!st.empty()) {
            TreeNode *t = st.top(); st.pop();
            if (!t->left && !t->right) {
                if (t->val == sum) return true;
            }
            if (t->right) {
                t->right->val += t->val;
                st.push(t->right);
            }
            if (t->left) {
                t->left->val += t->val;
                st.push(t->left);
            }
        }
        return false;
    }
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	TreeNode e(5);
	SolutionII solve;
	a.left = &b;
	a.right = &c;
	b.left = &d;
	d.right = &e;
	
	cout << "ture or false ? : " << solve.hasPathSum(&a,12) << endl;
	cout << "ture or false ? : " << solve.hasPathSum(&a,7) << endl;
	return 0;
}
