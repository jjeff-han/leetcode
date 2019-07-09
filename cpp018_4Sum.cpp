
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int> > res;
        int n = nums.size(),count = 0;
		sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        //vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        //res.push_back(out);
						cout << count << endl;
						res.push_back(vector<int>());
                        res[count].push_back(nums[i]);
                        res[count].push_back(nums[j]);
                        res[count].push_back(nums[left]);
                        res[count].push_back(nums[right]);
						count ++;
						cout << count << endl;

                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return res;
    }
};


int main(void){
	Solution solve;

	vector<int> nums;
	vector<vector<int> > res;
	int arr[] = {1, 0, -1, 0, -2, 2};
	for(int i=0; i<6; i++)
		nums.push_back(arr[i]);
	res = solve.fourSum(nums, 0);
	cout << "solve " << endl;
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++)
			cout << " " << res[i][j];
		cout << endl;
	}
	return 0;
}

