#include <stdio.h>

#include <vector>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
	std::vector<std::vector<int> > combinationSum2(
									std::vector<int>& candidates,
							 		int target){
        std::vector<std::vector<int> > result;
    	std::vector<int> item;
    	std::set<std::vector<int> > res_set;
    	std::sort(candidates.begin(), candidates.end());
        generate(0, candidates, result, item, res_set, 0, target);
        return result;
    }
private:
	void generate(int i, std::vector<int>& nums,
			std::vector<std::vector<int> > &result,
			std::vector<int> &item,
			std::set<std::vector<int> > &res_set,
			int sum, int target){
		if (i >= nums.size() || sum > target){
			return;
		}
		sum += nums[i];
		item.push_back(nums[i]);
		if (target == sum && res_set.find(item) == res_set.end()){
			result.push_back(item);
			res_set.insert(item);
		}
		generate(i + 1, nums, result, item, res_set, sum, target);
		sum -= nums[i];
		item.pop_back();
		generate(i + 1, nums, result, item, res_set, sum, target);
	}
};

class Solution2 {
public:
    vector<vector<int> > combinationSum2_gy(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> out;
        sort(num.begin(), num.end());
        combinationSum2DFS(num, target, 0, out, res);
        return res;
    }
    void combinationSum2DFS(vector<int> &num, int target, int start, vector<int> &out, vector<vector<int> > &res) {
        if (target < 0) return;
        else if (target == 0) res.push_back(out);
        else {
            for (int i = start; i < num.size(); ++i) {
                if (i > start && num[i] == num[i - 1]) continue;
                out.push_back(num[i]);
                combinationSum2DFS(num, target - num[i], i + 1, out, res);
                out.pop_back();
            }
        }
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(10);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(1);
	nums.push_back(5);
	std::vector<std::vector<int> > result;
	Solution2 solve;
	result = solve.combinationSum2_gy(nums, 8);
	for (int i = 0; i < result.size(); i++){
		if (result[i].size() == 0){
			printf("[]");
		}
		for (int j = 0; j < result[i].size(); j++){
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}
	Solution solve1;
	result = solve1.combinationSum2(nums, 8);
	for (int i = 0; i < result.size(); i++){
		if (result[i].size() == 0){
			printf("[]");
		}
		for (int j = 0; j < result[i].size(); j++){
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}
