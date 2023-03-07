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
    int partition (int arr[], int low, int high){
       // select the rightmost element as pivot
          int pivot = arr[high];
          
          // pointer for greater element
          int i = (low - 1);
        
          // traverse each element of the array
          // compare them with the pivot
          for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                
              // if element smaller than pivot is found
              // swap it with the greater element pointed by i
              i++;
              
              // swap element at i with element at j
              swap(arr[i], arr[j]);
            }
          }
          
          // swap pivot with the greater element at i
          swap(arr[i + 1], arr[high]);
          
          // return the partition point
          return (i + 1);
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