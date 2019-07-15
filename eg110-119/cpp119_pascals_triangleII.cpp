
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                res[j] += res[j - 1];
            	cout << i << " " << j << " " << res[j]  << " " << res[j-1] << endl;
            }
// 1 4 6 4 1  
        }
        return res;
    }
};

int main() {
	vector<int> res;
	Solution solve;
	res = solve.getRow(4);
	for(int i=0; i<res.size(); i++)
		cout << " " << res[i];
	cout << endl;
	return 0;
}
