
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//Example 1:
//
//Input: ["flower","flow","flight"]
//Output: "fl"
//
//Example 2:
//
//Input: ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.

class Solution{
public:
	string longestCommonPrefix(vector<string>& strs){
		if(strs.empty()) return "";
		string res = "";
		for(int j=0; j<strs[0].size(); j++){
			char c = strs[0][j];
			for(int i=1; i<strs[i].size(); i++) {
				if(j>=strs[i].size() || strs[i][j] != c)
					return res;
			}
			res.push_back(c);
		}
		return res;
	}
};


int main(void) {
	Solution solve;

	vector<string> strs;
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flidower");

	printf("%s\n",solve.longestCommonPrefix(strs).c_str());
	cout << "result is " << solve.longestCommonPrefix(strs) << endl;
	return 0;
}










