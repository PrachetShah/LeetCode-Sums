//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n){
        // code here 
        int zero = 0, one = 0, two = 0;
        for(int i=0; i<n; i++){
            if(a[i]==0)
                zero++;
            else if(a[i]==1)
                one++;
            else
                two++;
        }
        int i=0;
        while(zero > 0){
            a[i] = 0;
            zero--;
            i++;
        }
        while(one > 0){
            a[i] = 1;
            i++;
            one--;
        }
        while(two > 0){
            a[i] = 2;
            i++;
            two--;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends