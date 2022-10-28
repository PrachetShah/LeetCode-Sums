//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int num[], int n){
        
        // Your code here
        long long int max_so_far = 0, max_total = INT_MIN;
        for(int i=0; i<n; i++){
            max_so_far += num[i];
            
            if(max_so_far > max_total){
                max_total = max_so_far;
            }
            
            if(max_so_far < 0){
                max_so_far = 0;
            }
        }
        return max_total;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends