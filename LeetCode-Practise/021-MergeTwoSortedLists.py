'''
First you initialize dummy and temp. One is sitting at the start of the linkedlist and the other (temp) is going to move forward 
find which value should be added to the list. Note that it's initialized with a value 0 but it can be anything! You initialize it 
with your value of choice! Doesn't matter since we're going to finally return dummy.next which disregards 0 that we used to start 
the linkedlist. Line #1 makes sure none of the l1 and l2 are empty! If one of them is empty, we should return the other! If both 
are nonempty, we check val of each of them to add the smaller one to the result linkedlist! In line #2, l1.val is smaller and 
we want to add it to the list. How? We use temp POINTER (it's pointer, remember that!). Since we initialized temp to have value 
0 at first node, we use temp.next to point 0 to the next value we're going to add to the list l1.val (line #3). Once we do that,
we update l1 to go to the next node of l1. If the if statement of line #2 doesn't work, we do similar stuff with l2. And finally, 
if the length of l1 and l2 are not the same, we're going to the end of one of them at some point! Line #5 adds whatever left from 
whatever linkedlist to the temp.next (check the above video for a great explanation of this part). Note that both linkedlists were 
sorted initially. Also, this line takes care of when one of the linkedlists are empty. Finally, we return dummy.next since dummy is 
pointing to 0 and next to zero is what we've added throughout the process.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = temp = ListNode(0)
        while list1 != None and list2 != None:
            if list1.val < list2.val:
                temp.next = list1
                list1 = list1.next
            else:
                temp.next = list2
                list2 = list2.next
            temp = temp.next
        temp.next = list1 or list2
        return dummy.next

      
      
'''
Another way of solving is problem is by doing recursion. This is from here. The first check is obvious! If one of them is empty, return the other one! 
Similar to line #5 of previous solution. Here, we have two cases, whatever list has the smaller first element (equal elements also satisfies line #1), 
will be returned at the end. In the example l1 = [1,2,4], l2 = [1,3,4], we go in the if statement of line #1 first, this means that the first element of l1 
doesn't get changed! Then, we move the pointer to the second element of l1 by calling the function again but with l1.next and l2 as input! This round of call, 
goes to line #2 because now we have element 1 from l2 versus 2 from l1. Now, basically, l2 gets connected to the tail of l1. We keep moving forward by switching 
between l1 and l2 until the last element. Sorry if it's not clear enough! I'm not a fan of recursion for such a problems! But, let me know which part it's hard 
to understand, I'll try to explain better!

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:   
        if not l1 or not l2:
            return l1 or l2
        
        if l1.val <= l2.val: #1
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else: #2
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2
'''
