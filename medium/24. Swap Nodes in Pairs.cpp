// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.



// Idea:
// use the method of recursion
// create a new node to store the next node, use recursion for the next next node, and replace the current node

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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        ListNode* temp = head->next;
        temp->next = swapPairs(temp->next);
        head->next = temp->next;
        temp->next = head;
        return temp;
    }
};