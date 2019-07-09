
#include<vector>
#include<iostream>

using namespace std;

// Two binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int left = 0, right = matrix.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) left = mid + 1;
            else right = mid - 1;
        }
        int tmp = right;
        left = 0;
        right = matrix[tmp].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[tmp][mid] == target) return true;
            else if (matrix[tmp][mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};


int main(){
	Solution solve;
	int nums[3][4] = {{1,   3,  5,  7},{10, 11, 16, 20},{23, 30, 34, 50}};
	vector<vector<int> > mat;
	for(int i=0; i<3; i++){
		mat.push_back(vector<int>());
		for(int j=0; j<4; j++)
			mat[i].push_back(nums[i][j]);
	}
	cout << solve.searchMatrix(mat, 30) << endl;


	return 0;
}
