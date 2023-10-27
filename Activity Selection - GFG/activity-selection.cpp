//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> s, vector<int> f, int n)
    {
        // Your code here
        vector<pair<int, int> > ans;
        vector<pair<int, int>> activity;
        for(int i=0; i<n; i++){
            activity.push_back({f[i], s[i]});
        }
        
        sort(activity.begin(), activity.end());
        
        int last = activity[0].first;
        int count = 1;
        
        for(int i=1; i<n; i++){
            if(last < activity[i].second){
                last = activity[i].first;
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends