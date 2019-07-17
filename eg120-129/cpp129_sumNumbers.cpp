
#include<stack>
#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbersDFS(root, 0);
    }
    int sumNumbersDFS(TreeNode* root, int sum) {
        if (!root) 
        	return 0;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) 
        	return sum;
        return sumNumbersDFS(root->left, sum) + sumNumbersDFS(root->right, sum);
    }
};

class SolutionII {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) 
        	return 0;
        int res = 0;
        stack<TreeNode*> st;//{{root}};
        st.push(root);
        while (!st.empty()) {
            TreeNode *t = st.top(); 
            st.pop();
            if (!t->left && !t->right) {
                res += t->val;
            }
            if (t->right) {
                t->right->val += t->val * 10;
                st.push(t->right);
            }
            if (t->left) {
                t->left->val += t->val * 10;
                st.push(t->left);
            }
        }
        return res;
    }
};

int main() {
	Solution solve;
	SolutionII solve2;
	TreeNode a(4);
	TreeNode b(9);
	TreeNode c(5);
	TreeNode d(1);
	TreeNode e(0);
	a.left = &b;
	b.left = &c;
	b.right = &d;
	a.right = &e;
	
	cout << "sum : " << solve.sumNumbers(&a) << endl;
	cout << "sum2 : " << solve2.sumNumbers(&a) << endl;
	
	return 0;
}




