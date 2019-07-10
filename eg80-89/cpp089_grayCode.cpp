
#include<vector>
#include<math.h>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n){
		vector<int> res;
		for(int i=0; i<pow(2,n); i++){
			res.push_back((i >> 1)^i);
		}
		return res;
	}
private:
/*
        The purpose of this function is to convert an unsigned
        binary number to reflected binary Gray code.
 
        The operator >> is shift right. The operator ^ is exclusive or.
*/
	unsigned int binaryToGray(unsigned int num)
	{
		return (num >> 1) ^ num;
	}
 
/*
        The purpose of this function is to convert a reflected binary
        Gray code number to a binary number.
*/
	unsigned int grayToBinary(unsigned int num)
	{
	    unsigned int mask;
	    for (mask = num >> 1; mask != 0; mask = mask >> 1)
	    {
		num = num ^ mask;
	    }
	    return num;
	}
};

int main(){
	Solution solve;
	vector<int> res;
	res = solve.grayCode(2);
	for(int i=0;i<res.size(); i++)
		cout << res[i]<<endl;
	cout<< "GrayCode of 3: "<< endl;
	res = solve.grayCode(3);
	for(int i=0;i<res.size(); i++)
		cout << res[i]<<endl;
	return 0;
}

