#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    
	    long long int A=0;
	    int sign = 1;
	    for(int i=n-1; i>=0; i--){
	        if(sign){
	            A += arr[i]*arr[i];
	            sign--;
	        }else{
	            A -= arr[i]*arr[i];
	            sign++;
	        }
	    }
	    cout << A << endl;
	}
	return 0;
}