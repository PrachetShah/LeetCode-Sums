//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int n, vector<int> &A) {
        // code here
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = A[0];
        right[n-1] = A[n-1];
        for(int i=1; i<n; i++){
            left[i] = A[i] + left[i-1];
        }
        
        for(int i=n-2; i>=0; i--){
            right[i] = right[i+1] + A[i]; 
        }
        
        for (int i = 0; i < n; i++) {
            if (left[i] == right[i]) {
                // since 1-indexed array
                return i+1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends