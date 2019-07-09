
#include <stdio.h>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> parentheses;
		for(int i=0; i<s.size(); i++) {
			if(s[i] == '(' || s[i] == '[' || s[i] == '{')
				parentheses.push(s[i]);
			else {
				if(parentheses.empty())
					return false;
				if(s[i] == ')' && parentheses.top() != '(') return false;
				if (s[i] == ']' && parentheses.top() != '[') return false;
				if (s[i] == '}' && parentheses.top() != '{') return false;
				parentheses.pop();
			}
		}
		return parentheses.empty();
	}
};

int main(void) {
	Solution solve;
	
	printf("the result is %d\n",solve.isValid("{([]){}}"));
	printf("the result is %d\n",solve.isValid("([)){}"));

	return 0;
}

