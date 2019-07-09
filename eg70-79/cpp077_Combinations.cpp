
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> out;
        helper(n, k, 1, out, res);
        return res;
    }
    void helper(int n, int k, int level, vector<int>& out, vector<vector<int> >& res) {
        if (out.size() == k) {
			res.push_back(out); 
			return;
		}
        for (int i = level; i <= n; ++i) {
            out.push_back(i);
            helper(n, k, i + 1, out, res);
            out.pop_back();
        }
    }
};

int main(){
	Solution solve;
	vector<vector<int> > res;
	res = solve.combine(4,2);
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++)
			cout << " " << res[i][j];
		cout << endl;
	}
	return 0;
}
