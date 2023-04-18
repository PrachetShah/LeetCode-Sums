//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  private:
    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node* left, Node* right){
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        
        Node* ptr = left;
        if(left->data > right->data){
            ptr = right;
            right = right->next;
        }else{
            left = left->next;
        }
        
        Node* curr = ptr;
        
        while(left && right){
            if(left->data > right->data){
                curr->next = right;
                right = right->next;
            }else{
                curr->next = left;
                left = left->next;
            }
            curr = curr->next;
        }
        if(!left){
            curr->next = right;
        }else{
            curr->next = left;
        }
        return ptr;
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {

        // Base Case
        if(head == NULL || head->next == NULL){
            return head;
        }
        // find mid of LL to split
        Node* mid = findMid(head);
        
        Node* left = head;
        Node* right = mid->next;
        // since left->next will be mid->next
        mid->next = NULL;
        
        // recursive call to split two halves
        left = mergeSort(left);
        right = mergeSort(right);
        
        // merge both left and right
        Node* result = merge(left, right);
        return result;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends