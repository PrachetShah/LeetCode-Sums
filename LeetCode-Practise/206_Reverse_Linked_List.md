## Python Solution
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return head
        p = None
        while(head != None):
            temp = head.next
            head.next = p
            p = head
            head = temp
        return p
```

## C Solution (Faster than 100%)
```
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
```
