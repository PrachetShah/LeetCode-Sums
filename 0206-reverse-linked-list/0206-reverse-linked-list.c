/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->val = head->val;
    p->next = NULL;
    head = head->next;
    while(head!=NULL){
        struct ListNode* temp = p;
        p = head;
        head = head->next;
        p->next = temp;
    }
    return p;
}