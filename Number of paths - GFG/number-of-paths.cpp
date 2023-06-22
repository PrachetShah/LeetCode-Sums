//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
long long  numberOfPaths(int m, int n)
{
    // Code Here
    int count[m][n];
    for(int i=0; i<m; i++){
        count[i][0] = 1;
    }
    for(int i=0; i<n; i++){
        count[0][i] = 1;
    }
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            count[i][j] = count[i-1][j] + count[i][j-1];
        }
    }
    return count[m-1][n-1];
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends