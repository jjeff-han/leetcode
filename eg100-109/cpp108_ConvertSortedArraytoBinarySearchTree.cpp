#include <stdio.h>

#include <vector>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void BST_insert(TreeNode *node, TreeNode *insert_node){
	if (insert_node->val < node->val){
		if (node->left){
			BST_insert(node->left, insert_node);
		}
		else{
			node->left = insert_node;
		}
	}
	else{
		if (node->right){
			BST_insert(node->right, insert_node);
		}
		else{
			node->right = insert_node;
		}
	}
}

void preorder_insert(const std::vector<int> &nums,
					 std::vector<TreeNode *> &node_vec,
					 int begin, int end){
	if (begin > end){
		return;
	}
	int mid = (begin + end) / 2;
	node_vec.push_back(new TreeNode(nums[mid]));
	preorder_insert(nums, node_vec, begin, mid - 1);
	preorder_insert(nums, node_vec, mid + 1, end);
}

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    	if (nums.size() == 0){
	    	return NULL;
	    }
    	std::vector<TreeNode *> node_vec;
    	preorder_insert(nums, node_vec, 0, nums.size() - 1);
    	for (int i = 1; i < node_vec.size(); i++){
			BST_insert(node_vec[0], node_vec[i]);
		}
		return node_vec[0];
    }
   TreeNode* sortedArrayToBSTII(vector<int>& nums) {
        return helper(nums, 0 , (int)nums.size() - 1);
    }
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = left + (right - left) / 2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = helper(nums, left, mid - 1);
        cur->right = helper(nums, mid + 1, right);
        return cur;
    }
};


void preorder_print(TreeNode *node,int layer){
	if (!node){
		return;
	}
	for (int i = 0; i < layer; i++){
		printf("-----");
	}
	printf("[%d]\n", node->val);
	preorder_print(node->left, layer + 1);
	preorder_print(node->right, layer + 1);
}

int main(){
	int test[] = {-10, -3, 0, 5, 9};
	std::vector<int> nums;
	for (int i = 0; i < 5; i++){
		nums.push_back(test[i]);
	}
	Solution solve;
	TreeNode *root = solve.sortedArrayToBST(nums);
	preorder_print(root, 0);
	TreeNode *res = solve.sortedArrayToBSTII(nums);
	preorder_print(res, 0);
	return 0;
}

