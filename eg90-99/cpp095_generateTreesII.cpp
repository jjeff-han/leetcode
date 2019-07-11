
#include<stdio.h>
#include<vector>
#include<stack>
#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

/*
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) 
			return {};
        return helper(1, n);
    }
    vector<TreeNode*> helper(int start, int end) {
        if (start > end) 
			return {nullptr};
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            auto left = helper(start, i - 1), right = helper(i + 1, end);
            for (auto a : left) {
                for (auto b : right) {
                    TreeNode *node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};*/
class Solution {
public:
         
    vector<TreeNode *> generateTrees(int n) {
        return generateTreeDFS(1, n);
    }
     
    vector<TreeNode *> generateTreeDFS(int start, int end){
         
        vector<TreeNode *> subTree;//不用指针的话，不能动态生成数组new vector<TreeNode *>
        if(start > end) subTree.push_back(NULL);
        else{
            for(int i=start; i<=end; i++){
                vector<TreeNode *> leftsubTree = generateTreeDFS(start, i-1);
                vector<TreeNode *> rightsubTree = generateTreeDFS(i+1, end);
               
                int l = leftsubTree.size(),r = rightsubTree.size();
                for(int j = 0; j < l; j++)
                    for(int k = 0; k < r; k++){
                        TreeNode *root = new TreeNode(i);
                        root->left = leftsubTree[j];
                        root->right = rightsubTree[k];
                        subTree.push_back(root);
                    }
            }
        }
        return subTree;
    }
};

int main(){

	Solution solve;
	vector<TreeNode *> res;
	stack<TreeNode *> s;
	res = solve.generateTrees(3);
	for(int i=0; i<res.size(); i++){
		s.push(res[i]);
		while(!s.empty()){
			TreeNode * tmp = s.top();
			s.pop();
			cout << tmp->val << "->";
			if(tmp->left)
				s.push(tmp->left);
			if(tmp->right)
				s.push(tmp->right);
		}
		cout << endl;
	}
	return 0;

}

