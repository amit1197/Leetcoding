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
    ListNode* prev=nullptr;
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return prev;
        ListNode* curr=head;
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        return reverseList(next);
        
    }
    
};