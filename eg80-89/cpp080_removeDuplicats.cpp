
#include<stdio.h>
int A[] = {1,1,1,2,2,3};
int n = 6;
int main() {
        if (n <= 2) 
			return n;
        int pre = 0, cur = 1, count = 1;
        while (cur < n) {
            if (A[pre] == A[cur] && count == 0) 
				++cur;
            else {
                if (A[pre] == A[cur]) 
					--count;
                else 
					count = 1;
                A[++pre] = A[cur++];
            }
        }
		printf("Total is %d .\n", pre+1);
        return 1;
    }
