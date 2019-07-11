#include<stdio.h>
#include<vector>
#include<stack>

using namespace std;
/**
 * Definition for binary tree
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> >res;
        if (!root) 
			return res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        vector<int> out;
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                TreeNode *cur = s1.top();
                s1.pop();
                out.push_back(cur->val);
                if (cur->left) 
					s2.push(cur->left);
                if (cur->right) 
					s2.push(cur->right);
            } 
            if (!out.empty()) 
				res.push_back(out);
            out.clear();
            while (!s2.empty()) {
                TreeNode *cur = s2.top();
                s2.pop();
                out.push_back(cur->val);
                if (cur->right) 
					s1.push(cur->right);
                if (cur->left) 
					s1.push(cur->left);
            }
            if (!out.empty()) 
				res.push_back(out);
            out.clear();
        }
        return res;
    }
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }    
};

int main(){
	Solution solve;
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
	vector<vector<int> > res;
	a.left = &b;
	a.right = &c;
	b.left = &d;
	d.right = &e;
	//b.right = &e;
	c.right = &f;
	res = solve.zigzagLevelOrder(&a);
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++)
			printf(" %d", res[i][j]);
		printf("\n");
	}
	printf("The max depth is %d \n", solve.maxDepth(&a));
	return 0;
}


