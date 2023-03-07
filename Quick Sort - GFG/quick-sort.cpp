//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int s, int e){
        // base case
        if(s >= e){
            return;
        }
        
        // partition the arr
        int pivot = partition(arr, s, e);
        // recursive call
        quickSort(arr, s, pivot-1);
        quickSort(arr, pivot+1, e);
    }
    
    public:
    // PIVOT AT START
    // int partition(int arr[], int s, int e){
    //     int pivot = arr[s];
    //     int j=e;
    //     for(int i=e; i>s; i--){
    //         if(arr[i] > pivot){
    //             swap(arr[i], arr[j]);
    //             j--;
    //         }
    //     }
    //     swap(arr[j], arr[s]);
    //     return j;
    // }
    // PIVOT AT END
    int partition (int arr[], int low, int high){
      // select the rightmost element as pivot
          int pivot = arr[high];
          int i = (low);
    
          for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {              
              swap(arr[i++], arr[j]);
            }
          }
          swap(arr[i], arr[high]);

          return (i);
    }
    
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends