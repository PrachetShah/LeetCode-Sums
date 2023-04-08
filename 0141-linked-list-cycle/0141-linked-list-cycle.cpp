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
    bool hasCycle(ListNode *head) {
       ListNode* first = head;
       map<ListNode*, bool> seen;
       while(head){
           if(seen.find(head) != seen.end()){
               return true;
           }else{
               seen[head] = true;
           }
           head = head->next;
       }
       return false;
    }
};