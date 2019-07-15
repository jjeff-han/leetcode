
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        if (!root) 
        	return {};
        vector<vector<int> > res;
        queue<TreeNode*> q;//{{root}};
        q.push(root);
        while (!q.empty()) {
            vector<int> oneLevel;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *t = q.front(); 
                q.pop();
                oneLevel.push_back(t->val);
                if (t->left) 
                	q.push(t->left);
                if (t->right) 
                	q.push(t->right);
            }
            res.insert(res.begin(), oneLevel);
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
	TreeNode f(6);
	Solution solve;
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	vector<vector<int> > res;
	res = solve.levelOrderBottom(&a);
	for(int i=0; i<res.size(); i++){
		for(int j=0; j< res[i].size(); j++){
			cout << " " << res[i][j];
		}
		cout << endl;
	}
	return 0; 
}
