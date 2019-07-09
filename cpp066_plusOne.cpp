
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
		cout << digits[i] << digits[i-1] << endl;
        }
        if (digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
	Solution solve;
	vector<int> nums;
	for(int i=0; i<4; i++)
		nums.push_back(9);
	solve.plusOne(nums);
	for(int i=0; i<nums.size(); i++)
		cout << " "<< nums[i];
	cout << endl;

	return 0;
}
