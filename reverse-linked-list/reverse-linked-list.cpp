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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        // ListNode* next=curr->next;
        return reverse(prev,curr);
        
        
    }
    ListNode* reverse(ListNode* prev,ListNode* curr){
        if(curr==nullptr) return prev;
        if(curr->next==nullptr) {
            curr->next = prev;
            return curr;
        }
        ListNode* next=curr->next;
        ListNode* second=next->next;
        curr->next->next=curr;
        curr->next=prev;
        prev=next;
        curr=second;
        return reverse(prev,curr);
        
    }
    
};