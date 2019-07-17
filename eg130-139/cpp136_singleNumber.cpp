
#include<vector>
#include<set>
#include<iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> st;
        for (int i=0; i<nums.size(); i++) {
            if (st.count(nums[i])) 
            	st.erase(nums[i]);
            else 
            	st.insert(nums[i]);
        }
        return *st.begin();
    }
};

int main() {
	int arr[] = {4,1,2,1,2};
	vector<int> nums;
	Solution solve;
	for(int i=0; i<5; i++)
		nums.push_back(arr[i]);
	
	cout << "The number is : " << solve.singleNumber(nums) << endl;
	return 0;
}
