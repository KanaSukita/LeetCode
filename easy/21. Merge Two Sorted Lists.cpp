// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4



// Idea:
// create a list node first and link the smaller one of l1 and l2, finally return the next of the created list node

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode temp(INT_MAX);
        ListNode *res = &temp;
        while(l1 && l2){
            if(l1->val < l2->val){
                res->next=l1;
                l1=l1->next;
            }
            else{
                res->next=l2;
                l2=l2->next;
            }
            res = res->next;
        }
        res->next = l1? l1:l2;
        return temp.next;
    }
};