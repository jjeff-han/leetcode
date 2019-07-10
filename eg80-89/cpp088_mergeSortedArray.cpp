
#include<iostream>
using namespace std;
int main(){
	int nums[6] = {1,2,3,0,0,0};
	int nums2[3] = {2,5,6};
	int m = 2, n = 2, k = 5;
	while(m>=0 && n>=0){
		if(nums[m]>nums2[n])
			nums[k--] = nums[m--];
		else
			nums[k--] = nums2[n--];
	}
	while(n>=0)
		nums[k--] = nums2[n--];
	for(int i=0; i<6; i++)
		cout << i << "---" <<nums[i]<< endl;

	return 0;
}
