
#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};

int main() {
	int matric[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int n = 4;
	printf("org is :\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf(" %d",matric[i][j]);
		printf("\n");
	}
	for(int i=0; i<n/2; i++){
		for(int j=i; j<n-1; j++){
			int tmp = matric[i][j];
			matric[i][j] = matric[n-1-j][i];
			matric[n-1-j][i] = matric[n-1-i][n-1-j];
			matric[n-1-i][n-1-j] = matric[j][n-1-i];
			matric[j][n-1-i] = tmp;
		}
	}
	printf("res is :\n");
	for(int i=0; i<n; i++){
		 for(int j=0; j<n; j++)
		     printf(" %d",matric[i][j]);
		printf("\n");
	}
}

