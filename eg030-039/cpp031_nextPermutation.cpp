
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	int n = nums.size(), i = n - 2, j = n - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            while (nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main(){
	Solution solve;
	int a[] = {1,2,7,4,3,1};
	vector<int> nums;
	for(int i=0; i<6; i++)
		nums.push_back(a[i]);
	solve.nextPermutation(nums);
	for(int i=0; i<nums.size(); i++)
		printf(" %d",nums[i]);
	printf("\n");
	return 0;
}

