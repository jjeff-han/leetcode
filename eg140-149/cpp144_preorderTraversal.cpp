
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s;//{{root}};
        s.push(root);
        while (!s.empty()) {
            TreeNode *t = s.top(); '
            s.pop();
            res.push_back(t->val);
            if (t->right) 
            	s.push(t->right);
            if (t->left) 
            	s.push(t->left);
        }
        return res;
    }
};
