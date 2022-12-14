//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n){
        // code here 
        int zero=0, one=0, two=0;
        for(int i=0; i<n; i++){
            if(a[i]==0){
                zero++;
            }else if(a[i]==1){
                one++;
            }else{
                two++;
            }
        }
        int output[n];
        for(int i=0; i<zero; i++){
            a[i] = 0;
        }
        for(int i=zero; i<zero+one; i++){
            a[i] = 1;
        }
        for(int i=zero+one; i<n;i++){
            a[i] = 2;
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