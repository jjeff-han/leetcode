#include <stdio.h>

#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	std::vector<int> dp(n + 3, 0);
    	dp[1] = 1;
    	dp[2] = 2;
    	for (int i = 3; i <= n; i++){
	    	dp[i] = dp[i-1] + dp[i-2];
	    }
	    return dp[n];
	    //return dp.front();
    }
    int climbStairsII(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n);
        dp[0] = 1; dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n-1];//dp.back();
    }
};

int main(){
	Solution solve;
	printf("%d\n", solve.climbStairs(4));	
	printf("%d\n", solve.climbStairsII(4));
	return 0;
}
