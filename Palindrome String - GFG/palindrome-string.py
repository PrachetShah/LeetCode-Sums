#User function Template for python3
class Solution:
	def isPalindrome(self, S):
		# code here
		pali = S[::-1]
		if pali==S:
		    return 1
		return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		S = input()
		ob = Solution()
		answer = ob.isPalindrome(S)
		print(answer)

# } Driver Code Ends