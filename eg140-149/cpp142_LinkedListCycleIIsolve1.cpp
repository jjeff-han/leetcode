
#include <stdio.h>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#include <set>
class Solution {
public:
    ListNode *detectCycleSet(ListNode *head) {
        std::set<ListNode *> node_set;
        while(head){
        	if (node_set.find(head) != node_set.end()){
	        	return head;
	        }
	        node_set.insert(head);
        	head = head->next;
        }
        return NULL;
    }
    ListNode *detectCycle_re(ListNode *head) {
    	ListNode *fast = head;
    	ListNode *slow = head;
    	ListNode *meet = NULL;
    	while(fast && fast->next){
    		slow = slow->next;
    		fast = fast->next->next;
    		//if (!fast){
		    //	return NULL;
		    //}
		    //fast = fast->next;
		    if (fast == slow){
    			meet = fast;
    			break;
    		}
	    }
	    if (meet == NULL){
    		return NULL;
    	}
    	while(head && meet){
	    	if (head == meet){
	    		return head;
	    	}
	    	head = head->next;
	    	meet = meet->next;
	    }
        return NULL;
    }    
};

int main(){
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	//f.next = &c;
	Solution solve;
	ListNode *node = solve.detectCycleSet(&a);
	if (node){
		printf("%d\n", node->val);
	}
	else{
		printf("NULL\n");
	}
	return 0;
}
