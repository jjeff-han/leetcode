
#include<stdio.h>
#include<vector>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int res = 0, buy = prices[0];
        for (int i=0; i<prices.size(); i++) {
            buy = std::min(buy, prices[i]);
            res = std::max(res, prices[i] - buy);
        }
        return res;
    }
};

int main() {
	int a[] = {3,8,2,10,5};
	std::vector<int> price;
	Solution solve;
	for(int i=0; i<5; i++)
		price.push_back(a[i]);
	printf("maxProfit is %d .\n",solve.maxProfit(price));
	
	return 0;
}
