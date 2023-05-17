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
    ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next==NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = head;
        
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        
        ListNode* middle = mid(head);
        ListNode* left = head;
        
        ListNode* right = reverse(middle->next);

        middle->next = NULL;
        
        int sum = 0, value;
        while(left && right){
            value = left->val + right->val;
            sum = max(sum, value);
            left = left->next;
            right = right->next;
        }
        return sum;
    }
};