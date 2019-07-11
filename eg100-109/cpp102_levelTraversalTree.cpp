


#include <stdio.h>
#include <vector>
#include <queue>

struct TreeNode {
	int val;
	int level;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), level(0), left(NULL), right(NULL) {}
};

std::vector<TreeNode *> BFS_print(TreeNode* root){
	std::queue<TreeNode *> Q;
	root->level = 1;
	std::vector<TreeNode *> res;
	Q.push(root);
	res.push_back(root);
  	while(!Q.empty()){
  		TreeNode *node = Q.front();
   		Q.pop();
	   	printf("[%d]\n", node->val);
	   	if (node->left){
			node->left->level = node->level + 1;
			res.push_back(node->left);
	   		Q.push(node->left);
	   	}
	   	if (node->right){
			node->right->level = node->level + 1;
			res.push_back(node->right);
   			Q.push(node->right);
	   	}
   	}
	return res;
}

int main(){
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
	std::vector<TreeNode *> res;
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	res = BFS_print(&a);
	for(int i=0; i<res.size(); i++)
		printf("level %d is %d .\n", res[i]->level, res[i]->val);
	return 0;
}
