#User function Template for python3

class Solution:
    def sort012(self,nums,n):
        # code here
        zero, one, two = nums.count(0), nums.count(1), nums.count(2)
        index = 0
        for i in range(zero):
            nums[index] = 0
            index += 1
        for i in range(one):
            nums[index] = 1
            index += 1
        for i in range(two):
            nums[index] = 2
            index += 1



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        n=int(input())
        arr=[int(x) for x in input().strip().split()]
        ob=Solution()
        ob.sort012(arr,n)
        for i in arr:
            print(i, end=' ')
        print()

# } Driver Code Ends