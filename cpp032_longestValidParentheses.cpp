
#include<stdio.h>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0;
        stack<int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') 
		m.push(i);
            else if (s[i] == ')') {
                if (m.empty()) 
		    start = i + 1;
                else {
                    m.pop();
		    printf("m.top = %d %d %d\n", i,start, res);
                    res = m.empty() ? max(res, i - start + 1) : max(res, i - m.top());
                }
            }
        }
        return res;
    }
};

int main(){
	Solution solve;
	int res = solve.longestValidParentheses(")(()))()");
	printf("longest is %d\n", res);

	return 0;
}
