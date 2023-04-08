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
    int length(ListNode * node){
        int count=0;
        while(node){
            count++;
            node=node->next;
        }
        return count;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(length(head) < k){
            return head;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward;
        int count = 0;
        while(curr != NULL && count<k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        if(forward != NULL){
            head->next = reverseKGroup(forward, k);
        }
        return prev;
    }
};