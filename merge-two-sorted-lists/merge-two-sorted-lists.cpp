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
    /*
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list=new ListNode();
        ListNode* curr=list;
        
        curr->next=getMergeList(list1,list2);
        return curr->next;
    }
    
    ListNode* getMergeList(ListNode* list1, ListNode* list2){
        if(!list1 && !list2) {
            return getNode(list1,list2);
        }
        else if(!list1){
            return list2;
        }
        else{
            return list1;
        }
    }
    ListNode* getNode(ListNode* list1,ListNode* list2){
        ListNode* ans;
        if(list1->val > list2->val) {
            ans=list2;
            list2=list2->next;
        }
        else{
            ans=list1;
            list1=list1->next;
        }
        return ans;
    }
    */



    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        }
        else if(list2 == nullptr) {
            return list1;
        }
        else {
            if(list1->val <= list2->val) {
                list1->next = mergeTwoLists(list1->next,list2);
                return list1;
            }
            else{
                list2->next= mergeTwoLists(list1,list2->next);
                return list2;
            }
        }

        
    }
    
};
/*
---------------------------------------------------------------------------------
[1,2,3]  [1,3,4]

[1,1,2,3,3,4], k=0
    
    
    while(!list1 && !list2) {
        compare and put smaller node to the ans array
            [list1++ || list2++]
    }
    
*/


