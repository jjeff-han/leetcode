
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res(numRows, vector<int>());
        for (int i = 0; i < numRows; ++i) {
            res[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};



int main() {
	vector<vector<int> > res;
	Solution solve;
	res = solve.generate(4);
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++)
			cout << " " << res[i][j];
		cout << endl;
	}
	return 0;
}
