// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.



// Idea:
// use recursion, each time merge two list
// after each merge, push the new list to the lists vector and erase the two lists used to merge

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        while(lists.size() > 1){
            lists.push_back(helper(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode* helper(ListNode* l1, ListNode* l2){
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        else if(l1->val < l2->val){
            l1->next = helper(l1->next, l2);
            return l1;
        }
        else{
            l2->next = helper(l1, l2->next);
            return l2;
        }
    }
};