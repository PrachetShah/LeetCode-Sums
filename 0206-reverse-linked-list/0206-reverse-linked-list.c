/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prevNode = NULL, *nextNode = NULL;
    while(head != NULL){
        nextNode = head -> next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }
    return prevNode;
}