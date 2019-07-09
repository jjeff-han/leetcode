
#include <stdio.h>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
};

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *list, int n) {
		if(!list->next) return NULL;
		ListNode *pre = list, *cur = list;
		for(int i=0; i<n; i++)
			cur = cur->next;
		if(!cur)
			return list->next;
		while(cur->next){
			cur = cur->next;
			pre = pre->next;
		}
		pre->next = pre->next->next;
		return list;
	}
};

int main(void) {
	Solution solve;
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	ListNode *res = solve.removeNthFromEnd(&a, 1);
	while(res){
		printf("%d ",res->val);
		res = res->next;
	}

	return 0;
}


