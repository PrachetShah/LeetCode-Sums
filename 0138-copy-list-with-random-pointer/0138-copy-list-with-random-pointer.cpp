/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private:
        void insertAtTail(Node* &head, Node* &tail, int d){
            Node* newNode = new Node(d);
            if(head==NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            else{
                tail ->next = newNode;
                tail = newNode;
            }
        }
public:
    Node* copyRandomList(Node* head) {
        // create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp = temp->next;
        }
        
        // create a map
        unordered_map<Node*,Node*>oldtonew;
        Node* original = head;
        Node* clone = cloneHead;
        while(original != NULL && clone!=NULL){
            oldtonew[original]=clone;
            original = original->next;
            clone = clone->next;
        }
        original=head;
        clone = cloneHead;
        
        while(original!=NULL){
            clone->random = oldtonew[original->random];
            original = original->next;
            clone = clone->next;
        }
        return cloneHead;
    }
};