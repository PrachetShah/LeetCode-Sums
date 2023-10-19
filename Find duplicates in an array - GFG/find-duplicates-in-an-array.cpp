//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
        vector<int> ans;
        
        unordered_map<int, int> count;
        
        for(int i=0; i<n; i++){
            count[arr[i]]++;
        }
        
        for(auto s: count){
            if(s.second > 1){
                // ans.insert(s.first);
                ans.push_back(s.first);
            }
        }
        
        // vector<int> sub(ans.begin(), ans.end());
        sort(ans.begin(), ans.end());
        
        if(ans.size() < 1){
            return {-1};
        }else{
            return ans;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends