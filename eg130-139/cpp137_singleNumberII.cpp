
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        //for (auto num : nums) res ^= num;
        return res;
    }
};



class Solution2 {
public:
    int singleNumberII(vector<int>& nums) {
        int res = 0;
        vector<int>::iterator maxindex = max_element(nums.begin(), nums.end());
        int max_num = *maxindex / 2 + 1;
        cout << "max num is : " << max_num << endl;
        for (int i = 0; i < max_num && i < 32; ++i) { //32
            int sum = 0;
            cout << "sum : ";
            for (int j = 0; j < nums.size(); ++j) {
                sum += (nums[j] >> i) & 1;
                cout << " " << sum;
            }
            res |= (sum % 3) << i;
            cout << endl << res << endl;
        }
        return res;
    }
};

int main() {
	int arr[] = {2,88,1,2,1,1,2};
	vector<int> nums;
	Solution2 solve;
	for(int i=0; i<7; i++)
		nums.push_back(arr[i]);
	
	cout << "The number is : " << solve.singleNumberII(nums) << endl;
	return 0;
}
