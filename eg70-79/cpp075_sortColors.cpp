

#include<iostream>

using namespace std;

int main() {
	int cols[] = {1,0,2,0,2,1,1,0};
	int left = 0, right = 7, cur = 0;
	while(cur < right){
		cout << "cur = : " << cur << endl;
		if(cols[cur] == 0)
			swap(cols[cur++], cols[left++]);
		else if(cols[cur] == 2)
			swap(cols[cur++], cols[right--]);
		else
			cur++;
	}
	for(int i=0; i<8; i++)
		cout << cols[i] ;
	cout << endl;

	return 0; 
}
