

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        long res = 1;
        for (int i = n + 1; i <= 2 * n; ++i) {
            res = res * i / (i - n);
        }
        return res / (n + 1);
    }
};

int main() {
	int nums;
	cin >> nums;
	vector<int> dp(nums + 1);
	dp[0] = dp[1] = 1;
	for(int i=2; i<=nums; i++){
		for(int j=0; j<i; j++){
			dp[i] += dp[j]*dp[i-j-1];
		}
	}
	cout << dp[nums] << endl;
	Solution solve;
	cout << solve.numTrees(nums) << endl;
	return 0;
}

