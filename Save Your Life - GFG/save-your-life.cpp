//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          int len = w.length();
          vector<int> vec;
          string res = "";
          
          unordered_map<char, int> um;
          
          for(int i=0; i<n; i++) {
              um[x[i]] = b[i];
          }
          
          for(int i=0; i<len; i++) {
                if(um.find(w[i]) != um.end())
                    vec.push_back(um[w[i]]);
                else
                    vec.push_back(int(w[i]));
          }
         
          int start=0, end=0, s=0;
          int curr_sum = vec[0];
          int max_sum = vec[0];
          
          for(int i=1; i<len; i++) {
              
              if(vec[i] > vec[i] + curr_sum) {
                  curr_sum = vec[i];
                  s = i;
              }else
                curr_sum += vec[i];
                
                
              if(max_sum < curr_sum) {
                  max_sum = curr_sum;
                  start = s;
                  end = i;
              }
          }
          
          for(int i=start; i<=end; i++) {
              res += w[i];
          }
        
        
        return res;
          
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends