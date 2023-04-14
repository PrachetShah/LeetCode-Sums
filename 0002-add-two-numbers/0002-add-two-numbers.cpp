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
    void insertAtTail(ListNode* &head, ListNode* &tail, int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail -> next = temp;
            tail = temp;
        }
    }
    
    ListNode* addLL(ListNode* first, ListNode* second){
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        while(first || second || carry){
            int val1 = 0;
            if(first){
                val1 = first->val;
            }
            
            int val2 = 0;
            if(second){
                val2 = second->val;
            }
            
            int sum = val1 + val2 + carry;
            int digit = sum%10;
            
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            if(first){
                first = first->next;
            }
            if(second){
                second = second -> next;
            }
        }
        return ansHead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* first = reverse(l1);
        // ListNode* second = reverse(l2);
        
        ListNode* ans = addLL(l1, l2);
        
        // ans = reverse(ans);
        return ans;
    }
};

