

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
	int minimunmPathSum(vector<vector<int> > &grid) {
		int i,j;
		int m = grid.size(), n = grid[0].size();
		printf("size : %d, %d\n",m,n);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			printf("%d ",grid[i][j]);
		printf("\n");
	}

		if(grid.empty() || grid[0].empty())
			return 0;
		vector<vector<int> > dp(m, vector<int>(n,0));
		dp[0][0] = grid[0][0];
		for(i=1; i<m; i++)
			dp[i][0] = dp[i-1][0] + grid[i][0];
		for(j=1; j<n; j++)
			dp[0][j] = dp[0][j-1] + grid[0][j];
		for(i=1; i<m; i++){
			for(j=1; j<n; j++){
				dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
				printf("dp[%d][%d] is %d .\n",i,j,dp[i][j]);
			}
		}
		return dp[i-1][j-1];
	}
};

int main(){
	Solution solve;
	int nums[3][3] = {{1,3,1},{1,1,1},{4,2,1}};
	vector<vector<int> > grid;//(3, vector<int>(3));
	for(int i=0; i<3; i++){
		cout << i << ":";
		grid.push_back(vector<int>());
		for(int j=0; j<3; j++){
			grid[i].push_back(nums[i][j]);
			cout << nums[i][j];
		}
		cout << endl;
	}
	printf("grid size : %d, %d\n",grid.size(),grid[0].size());
	printf("The minimum path sum is: %d .\n", solve.minimunmPathSum(grid));

	return 0;
}

