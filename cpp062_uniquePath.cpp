

#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1]; 
            }
        }
        return dp[n - 1];
    }
    int uniquePaths2(int m, int n) {
		vector<vector<int> > dp(m+1, vector<int>(n+1,0));
		dp[0][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};


int main() {
	Solution solve;
	printf("There is %d path.\n",solve.uniquePaths2(7,3));

	return 0;
}


