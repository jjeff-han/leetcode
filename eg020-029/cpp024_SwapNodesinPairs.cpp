
#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
	ListNode temp(0);
	ListNode *pre = &temp;
	temp.next = head;
	while(pre->next && pre->next->next) {
		ListNode *t = pre->next->next;
		pre->next->next = t->next;
		t->next = pre->next;
		pre->next = t;
		pre = t->next;
	}
	return temp.next;
}

ListNode* swapPairs2(ListNode* head) {
    if (!head || !head->next) return head;
	ListNode *t = head->next;
    head->next = swapPairs(head->next->next);
	t->next = head;
    return t;
}
    ListNode* swapPairs3(ListNode* head) {
		        ListNode *dummy = new ListNode(-1), *pre = dummy;
				        dummy->next = head;
						        while (pre->next && pre->next->next) {
									            ListNode *t = pre->next->next;
												            pre->next->next = t->next;
															            t->next = pre->next;
																		            pre->next = t;
																					            pre = t->next;
																								        }
								        return dummy->next;
										    }
int main(void) {
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	//d.next = &e;
	//e.next = &f;
	ListNode *result = swapPairs2(&a);
	while(result) {
		printf("-> %d ", result->val);
		result = result->next;
	}

	return 0;
}
