// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list.If the number of nodes is not a multiple of k 
// then left - out nodes in the end should remain as it is.

// You may not alter the values in the nodes, only nodes itself may be changed.

// Only constant memory is allowed.

// For example,
// Given this linked list : 1->2->3->4->5

// For k = 2, you should return : 2->1->4->3->5

// For k = 3, you should return : 3->2->1->4->5



// Idea:
// Using the method of recursion
// find k + 1 nodes, like(1, 2, 3, 4, 5, null), reverse(5, 4, 3, 2, 1, null), always 1 more to further reverse.

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode * reverseKGroup(ListNode* head, int k) {
		ListNode* temp = head;
		for (int i = 0; i< k; i++) {
			if (!temp)
				return head;
			temp = temp->next;
		}
		ListNode* res = reverse(head, temp);
		head->next = reverseKGroup(temp, k);
		return res;
	}
	ListNode* reverse(ListNode* start, ListNode* end) {
		ListNode* last = end;
		while (start != end) {
			ListNode* temp = start->next;
			start->next = last;
			last = start;
			start = temp;
		}
		return last;
	}
};