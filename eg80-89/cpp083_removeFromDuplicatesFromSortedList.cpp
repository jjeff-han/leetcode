
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
   ListNode* deleteDuplicatesRecursion(ListNode* head) {
        if (!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        return (head->val == head->next->val) ? head->next : head;
    }

};

int main() {
	ListNode a(1);
	ListNode b(1);
	ListNode c(2);
	ListNode d(3);
	ListNode e(3);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	//d.next = &e;
	Solution solve;
	//ListNode *res = solve.deleteDuplicatesRecursion(&a);
	ListNode *res = solve.deleteDuplicates(&a);
	while(res->next){
		cout << res->val << "->";
		res = res->next;
	}
	cout << res->val << endl;
	return 0;
}





