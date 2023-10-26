//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        // O(n^2logk)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0; i<N; i++){
            int sum = 0;
            for(int j=i; j<N; j++){
                sum += Arr[j];
                if(minHeap.size()<K){
                    minHeap.push(sum);
                }else{
                    if(minHeap.top() < sum){
                        minHeap.pop();
                        minHeap.push(sum);
                    }
                }
            }
        }
        
        return minHeap.top();
        
        
        // O(n^2logn)
        // priority_queue<int> pq;
        
        // // pq.push(Arr[0]);
        // for(int i=0; i<N; i++){
        //     int sum = Arr[i];
        //     pq.push(sum);
        //     for(int j=i+1; j<N; j++){
        //         sum += Arr[j];
        //         pq.push(sum);
        //     }
        // }
        
        // // cout << pq.size() << endl;
        
        // for(int i=0; i<K-1; i++){
        //     pq.pop();
        // }
        
        // return pq.top();
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends