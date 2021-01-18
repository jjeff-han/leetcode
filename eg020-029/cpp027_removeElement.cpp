#include <stdio.h>

int main() {
	char arr[] = {1,2,3,4,5,4,7,3,5,1};
	int res = 0, target = 4;
	for(int i=0; i<10; i++)
		if(arr[i] != target)
			arr[res++] = arr[i];
	printf("\n res is %d\n", res);

	return 0;
}
