class Solution{
public:	
	int isPalindrome(string s){
	    // Your code goes here
	    int n = s.size();
	    for(int i=0; i<n/2; i++){
	        if(s[i] != s[n-i-1]){
	            return 0;
	        }
	    }
	    return 1;
	}
};
