//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s){
    // your code here
    if(s.size()%2 == 1){
        return -1;
    }
    
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }else{
            st.push(s[i]);
        }
    }
    int open=0, close=0;
    while(!st.empty()){
        if(st.top() == '{'){
            open++;
        }else{
            close++;
        }
        st.pop();
    }
    int ans = (open+1)/2 + (close+1)/2;
    return ans;
}