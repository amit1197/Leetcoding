/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        return swapper(head);
        
    }
    ListNode* swapper(ListNode* curr){
        if(!curr || !curr->next) return curr;
        ListNode* first=curr;
        ListNode* second=curr->next;
        
        first->next=swapper(second->next);
        second->next=first;
        
        return second;
    }
};