
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

//这道链表重排序问题可以拆分为以下三个小问题：
//1. 使用快慢指针来找到链表的中点，并将链表从中点处断开，形成两个独立的链表。
//2. 将第二个链翻转。
//3. 将第二个链表的元素间隔地插入第一个链表中。
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) 
        	return;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *last = mid, *pre = NULL;
        while (last) {
            ListNode *next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        while (head && pre) {
            ListNode *next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next;
            head = next;
        }
    }
};

int main() {
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	Solution solve;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	solve.reorderList(&a);
	ListNode *tmp = &a;
	while(tmp) {
		cout << "->" << tmp->val;
		tmp = tmp->next;
	}
	cout << endl;
	return 0;
}
	

