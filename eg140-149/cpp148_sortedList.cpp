

#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) 
        	return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) 
        	cur->next = l1;
        if (l2) 
        	cur->next = l2;
        return dummy->next;
    }
};

int main() {
	Solution solve;
	ListNode a(3);
	ListNode b(8);
	ListNode c(9);
	ListNode d(11);
	ListNode e(1);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	
	ListNode *res = solve.sortList(&a);
	while(res) {
		cout << "->" << res->val;
		res = res->next;
	}
	cout << endl;
	return 0;
	
}








