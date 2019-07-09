
#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
		ListNode temp(0);
		ListNode *pre = &temp;
		while(l1 && l2) {
			if(l1->val <= l2->val){
				pre->next = l1;
				l1 = l1->next;
			}
			else {
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next;
		}
		if(l1)
			pre->next = l1;
		if(l2)
			pre->next = l2;
		return temp.next;
	}
	ListNode* mergeTwoLists_recursion(ListNode* l1, ListNode* l2){
		if(!l1)
			return l2;
		if(!l2)
			return l1;
		if(l1->val <= l2->val)
			l1->next = mergeTwoLists_recursion(l1->next, l2);
		else
			l2->next = mergeTwoLists_recursion(l1, l2->next);
	}
};

int main(void) {
	Solution solve;
	ListNode a(1);
	ListNode b(2);
	ListNode c(4);
	ListNode d(1);
	ListNode e(3);
	ListNode f(4);
	a.next = &b;
	b.next = &c;
	d.next = &e;
	e.next = &f;
/*	
	ListNode *merged = solve.mergeTwoLists(&a, &d);
	while(merged){
		printf("->%d", merged->val);
		merged = merged->next;
	}
	printf("\n");
	a.next = &b;
	b.next = &c;
	d.next = &e;
	e.next = &f;
*/
	ListNode *rmerged = solve.mergeTwoLists_recursion(&a, &d);
	while(rmerged){
		printf("->%d", rmerged->val);
		rmerged = rmerged->next;
	}
	printf("\n");
	return 0;
}





