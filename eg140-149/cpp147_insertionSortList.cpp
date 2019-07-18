

#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1), *cur = &dummy;
        while (head) {
            ListNode *t = head->next;
            cur = &dummy;
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
                //cout<<"w---"<<cur->val<<endl;
            }
            head->next = cur->next;
            cur->next = head;
            head = t;
           // cout << "head : "<<head->val << cur->val << t->val << endl;
        }
        return dummy.next;
    }
};

int main() {
	ListNode a(4);
	ListNode b(2);
	ListNode c(8);
	ListNode d(1);
	Solution solve;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	
	ListNode *res = solve.insertionSortList(&a);
//	ListNode *tmp = res;
	while(res) {
		cout << "->" << res->val ;
		res = res->next;
	}
	cout << endl;
	return 0;
}
	
	
	
