//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
// Optimized Method
class Solution {
  public:
//   First -> Diameter and Second->Height
  pair<int, int> diameterFast(Node* root){
    //   Base Case
    if(root == NULL){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    
    pair<int, int> leftAns = diameterFast(root->left);
    pair<int, int> rightAns = diameterFast(root->right);
    
    int op1 = leftAns.first;
    int op2 = rightAns.first;
    int op3 = leftAns.second + 1 + rightAns.second;
    
    pair<int, int> ans;
    
    ans.first = max(op1, max(op2, op3));
    ans.second = max(leftAns.second, rightAns.second)+1;
    return ans;
  }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};
/*
SLOW METHOD
class Solution {
  private:
    int height(struct Node* root){
        // base case
        if(root==NULL){
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        // Base case
        if(root == NULL){
            return 0;
        }
        
        int left = diameter(root->left);
        int right = diameter(root->right);
        
        int comb = height(root->left)+height(root->right)+1;
        
        return max(left, max(right, comb));
    }
};
*/

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}

// } Driver Code Ends