
#include <stdio.h>
//#include <math.h>
#include <vector>


//Container With Most Water 装最多水的容器
class Solution {
public:
	int maxArea(std::vector<int> &height){
		int res = 0, i=0, j=height.size()-1;
		while(i<j){
			res = std::max(res, std::min(height[i],height[j]) * (j-i));
			//res = res > ((height[i]<height[j] ? height[i]:height[j])*(j-i)) ? res:((height[i]<height[j] ? height[i]:height[j])*(j-i));
			height[i]<height[j] ? ++i : --j;
		}
		return res;
	}
};

int main(void) {
	Solution solve;
	int a[] = {1,8,6,2,5,4,8,3,7};
	std::vector<int> nums;
	for(int i=0; i<9; i++)
		nums.push_back(a[i]);

	printf("maxArea is %d\n", solve.maxArea(nums));

	return 0;
}
