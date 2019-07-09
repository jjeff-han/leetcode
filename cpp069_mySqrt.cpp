
#include<iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 0, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x / mid >= mid) left = mid + 1;
            else right = mid;
        }
        return right - 1;
    }
};


int main(){
	Solution solve;
	cout << solve.mySqrt(8) << endl;
	cout << solve.mySqrt(15) << endl;
	return 0;
}
