// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int sum(int arr[], int n){
    if(n==0)
        return 0;
    
    if(n==1)
        return arr[0];
    
    return sum(arr+1, n-1) + arr[0];
}

bool linearSearch(int *arr, int size, int target){
    if(size == 0)
        return false;

    if(arr[0] == target)
        return true;
    
    return linearSearch(arr+1, size-1, target);
}

bool binarySearch(int arr[], int low, int high, int target){
    if(low > high)
        return false;

    int mid = low + (high-low)/2;
    if(arr[mid] == target){
        return true;
    }else if(arr[mid] > target){
        binarySearch(arr, low, mid-1, target);
    }else{
        binarySearch(arr, mid+1, high, target);
    }
}

int main() {
    // Write C++ code here
    int arr[] = {1,2,3,4,5,10};
    int arrLength = sizeof(arr)/sizeof(arr[0]);
    
    int ans = sum(arr, arrLength);
    cout<<"SUM of Array is: "<<ans<<endl;
    
    int num = 10;
    bool result = linearSearch(arr, arrLength, num);
    cout<<num <<" is present in Array using LS: "<<result<<endl;
    
    num = 10;
    result = binarySearch(arr, 0, arrLength-1, num);
    cout<<num <<" is present in Array using BS: "<<result<<endl;
    return 0;
}
