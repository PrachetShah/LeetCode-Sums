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
private:
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next== NULL){
            return true;
        }
        // step1 -> find mid
        ListNode* middle = getMid(head);
        
        //step2 -> reverse after mid
        ListNode* temp = middle->next;
        middle->next = reverse(temp);
        
        //step3 -> compare values
        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        while(head2){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        //step4 -> reverse to original
        // middle->next = reverse(temp);
        return true;
    }
};