class Solution:
    inversion_count=0  
    
    #Function to count inversions in the array.
    def inversionCount(self, a,n):
        global inversion_count
        inversion_count = 0
        self.merge_sort(a, 0, n - 1)
        #returning the count of inversions in the array.
        return inversion_count
    
    #Function to sort and merge two parts of array.
    def merge(self, a, start, mid, end):
        global inversion_count
        temp = [0 for i in range(end - start + 1)]
        
        #i is pointer for left subarray.
        #j is pointer for right subarray.
        #k is index for resultant merged subarray.
        i, j, k = start, mid + 1, 0  
        
        #Using two pointers over the array which helps in storing the
        #smaller element and thus merging the subarray.
        while (i <= mid and j <= end):
            
            #Comparing element of the array at pointers i and j and accordingly
            #storing the smaller element and updating the pointers.
            if (a[i] <= a[j]):
                temp[k] = a[i]
                k += 1
                i += 1
            else:
                temp[k] = a[j]
                k += 1
                j += 1
                #Adding the inversions which is the number of elements which 
                #are smaller than arr[j] in the left half of the array.
                inversion_count += mid - i + 1
    
      #Copying the remaining elements of left subarray(if there are any)to temp.
        while (i <= mid):
            temp[k] = a[i]
            k += 1
            i += 1
    
      #Copying the remaining elements of right subarray(if there are any)to temp. 
        while (j <= end):
            temp[k] = a[j]
            k += 1
            j += 1
            
        #Copying back the merged elements to original array.
        for i in range(start, end + 1):
            a[i] = temp[i - start]
    
    #Function to mergesort the array, which uses divide and conquer algorithm
    #on left and right halves of array for mergesort operation.
    def merge_sort(self, a,start,end):
        
        if (start < end):
            
            mid = (start + end) // 2
            #Calling recursive function to sort left half of the array.
            self.merge_sort(a, start, mid)
            
            #Calling recursive function to sort right half of the array.
            self.merge_sort(a, mid + 1, end)
            
            #Calling merge function which sorts and merges both halves
            #of the array obtained after calling both recursive function.
            self.merge(a, start, mid, end)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for tt in range(t):
        n = int(input())
        a = list(map(int, input().strip().split()))
        obj = Solution()
        print(obj.inversionCount(a,n))
# } Driver Code Ends