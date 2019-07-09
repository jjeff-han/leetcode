

#include<stdio.h>
#include<vector>

using namespace std;

void permuteDFS(vector<int> &num, int level, vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
	if(level == num.size()){
		for(int i=0; i<out.size(); i++)
			printf(" %d",out[i]);
		printf("---\n");
		res.push_back(out);
		return ;
	}
	for(int i=0; i<num.size(); i++){
		if(visited[i] == 1)
			continue;
		visited[i] = 1;
		out.push_back(num[i]);
		permuteDFS(num, level+1, visited, out, res);
		out.pop_back();
		visited[i] = 0;
	}
}


vector<vector<int> > permute(vector<int> nums) {
	vector<vector<int> > res;
	vector<int> out,visited(nums.size(), 0);
	permuteDFS(nums, 0, visited, out, res);
	return res;
}

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int> > result;
	result = permute(nums);
	for(int i=0; i<result.size(); i++) {
		for(int j=0; j<result[i].size(); j++)
			printf(" %d", result[i][j]);
		printf("\n");
	}

	return 0;
}

