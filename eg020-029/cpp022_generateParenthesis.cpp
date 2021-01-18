#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string>generateParenthesis(int n){
		vector<string> res;
		generateParenthesisDFS(n, n, "", res);
		return res;
	}

private:
	void generateParenthesisDFS(int left, int right, string output, vector<string> &res){
		if(left > right)
			return ;
		if(left == 0 && right == 0)
			res.push_back(output);
		else {
			if(left > 0)
				generateParenthesisDFS(left-1, right, output + '(', res);
			if(right > 0) 
				generateParenthesisDFS(left, right-1, output + ')', res);
		}
	}
};

int main(void) {
	Solution solve;
	vector<string> pairs ;
	pairs = solve.generateParenthesis(3);
	for(int i=0; i<pairs.size(); i++)
		printf("%s\n", pairs[i].c_str());

	return 0;
}

