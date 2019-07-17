
#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size();
        for (int i = 0; i < n - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }
};

int main() {
	int a[] = {1,3,2,10,11};
	std::vector<int> price;
	Solution solve;
	for(int i=0; i<5; i++)
		price.push_back(a[i]);
	printf("maxProfit is %d .\n",solve.maxProfit(price));
	
	return 0;
}
