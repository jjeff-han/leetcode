
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;
//Integer to Roman 整数转化成罗马数字
//Roman numerals are represented by seven different symbols: I-1, V-5, X-10, L-50, C-100, D-500 and M-1000.
//the number four is written as IV. Because the one is before the five we subtract it making four.
// The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//I can be placed before V (5) and X (10) to make 4 and 9. 
//X can be placed before L (50) and C (100) to make 40 and 90. 
//C can be placed before D (500) and M(1000) to make 400 and 900.
//Input: 1994
//Output: "MCMXCIV"
//Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
//整数 1437 的罗马数字为 MCDXXXVII
class Solution {
public:
	string intToRoman(int num){
		string res = "";
		//std::vector<char> roman{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
		char roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
		//std::vector<int> value{1000, 500, 100, 50, 10, 5, 1};
		int value[] = {1000, 500, 100, 50, 10, 5, 1};
		for(int n=0; n<7; n+=2) {
			int x = num / value[n];
			if(x < 4) {
				for(int i=1; i<=x; ++i)
					res += roman[n];
			}
			else if(x == 4){
				res = res + roman[n] + roman[n-1];
			}
			else if(x>4 && x<9) {
				res += roman[n-1];
				for(int i=6; i<=x; ++i) 
					res += roman[n];
			}
			else if (x==9){
				res = res + roman[n] + roman[n-2];
			}
			num %= value[n];
		}
		return res;
	}
	string intToRoman2(int num){
         char roman[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
         int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		 string res = "";
		 for(int i=0; i<sizeof(value); i++){
			 while(num >= value[i]) {
				 num -= value[i];
				 res.append(roman[i]);
			 }
		 }
		 return res;
	}
//1、相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
//2、小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
//3、小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；
//4、正常使用时，连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）
//5、在一个数的上面画一条横线，表示这个数扩大1000倍。	
	int romanToInt(string s) {
		int res = 0;
		map<char, int> m;
		m.insert(pair<char,int>('I', 1)); 
		m.insert(pair<char,int>('V', 5));
	   	m.insert(pair<char,int>('X', 10));
	   	m.insert(pair<char,int>('L', 50)); 
		m.insert(pair<char,int>('C', 100));
		m.insert(pair<char,int>('D', 500));
		m.insert(pair<char,int>('M', 1000));
		for(int i=0; i<s.size(); i++) {
			int val = m[s[i]];
//第一，如果当前数字是最后一个数字，或者之后的数字比它小的话，则加上当前数字。
//第二，其他情况则减去这个数字。			
			if(i==s.size()-1 || m[s[i+1]]<m[s[i]])
				res +=val;
			else
				res -= val;
		}
		return res;
	}
 
};

int main(void) {
	Solution solve;
/*	int a[] = {1,8,6,2,5,4,8,3,7};
	std::vector<int> nums;
	for(int i=0; i<9; i++)
		nums.push_back(a[i]);

	printf("maxArea is %d\n", solve.maxArea(nums));
*/
	printf("Res = %s\n", solve.intToRoman(1994).c_str());
	printf("Res = %d\n", solve.romanToInt("MCMXCIV"));
	return 0;
}
