//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class node{
    public:
    int data, row, col;
    
    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k){
         //code here
        priority_queue<node*, vector<node*>, compare> minHeap;
        int maxi=INT_MIN, mini=INT_MAX;
        
        for(int i=0; i<k; i++){
            int element = arr[i][0];
            minHeap.push(new node(element, i, 0));
            maxi = max(maxi, element);
            mini = min(mini, element);
        }
        
        int start=mini, end=maxi;
        
        while(!minHeap.empty()){
            node* temp = minHeap.top();
            minHeap.pop();
            
            mini = temp->data;
            
            if(maxi-mini < end-start){
                start = mini;
                end = maxi;
            }
            
            if(temp->col+1 < n){
                int r = temp->row, c=temp->col;
                maxi = max(maxi, arr[r][c+1]);
                minHeap.push(new node(arr[r][c+1], r, c+1));
            }else{
                break;
            }
        }
        // cout << minHeap.top()->data << endl;
        return {start, end};
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends