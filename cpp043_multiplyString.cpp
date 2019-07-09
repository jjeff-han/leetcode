

#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2){
		string res = "";
		int m = num1.size(), n = num2.size();
		vector<int> vals(m+n);
		for(int i=m-1; i>=0; i--){
			for(int j=n-1; j>=0; j--) {
				int mul = (num1[i]-'0')*(num2[j]-'0');
				int p1 = i + j, p2 = i+j+1;
				int sum = mul + vals[p2];
				vals[p1] += sum / 10;
				vals[p2] = sum % 10;
			}
		}
		if(vals[0] != 0)
			res.push_back(vals[0]+'0');
		for(int val=1; val<vals.size(); val++) {
			res.push_back(vals[val]+'0');
		}
		//return res.empty()? "0": res;
		return res;
	}
};

int main() {
	Solution solve;

	string result = solve.multiply("123","456" );
//	for(int i=0; i<result.size(); i++)
//		printf("%d", result[i]);
	printf("\nstring is:%s\n", result.c_str());

	return 0;
}
