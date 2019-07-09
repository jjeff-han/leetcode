#include<stdio.h>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) 
			return 1;
        double half = myPow(x, n / 2);
        if (n % 2 == 0) 
			return half * half;
        if (n > 0) 
			return half * half * x;
        return half * half / x;
    }
};

int main(){
	Solution solve;

	double res;

	res = solve.myPow(2.0,-2);
	printf("%lf \n",res);
	res = solve.myPow(2.1,3);
	printf("%lf \n",res);
	res = solve.myPow(2.0,10);
	printf("%lf \n",res);
	return 0;
}
