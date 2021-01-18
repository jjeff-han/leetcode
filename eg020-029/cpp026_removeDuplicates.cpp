
#include <stdio.h>
int removeDuplicates(unsigned char arr[], int n) {
	if(n<1)
		return 0;
	int j=0;
	for(int i=0; i<n; i++){
		if(arr[i] != arr[j])
			arr[++j] = arr[i];
	}
	return j+1;
}

int main(){
	unsigned char a[10] = {0,0,1,1,1,2,2,3,3,4};

	printf("\nsize = %ld\n", sizeof(a));
	int cnt = removeDuplicates(a, 10);

	printf("\ncnt is %d\n", cnt);

	return 0;
}
