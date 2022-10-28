class Solution {
public:
    void reverseString(vector<char>& s) {
        long long int n = s.size();
        
		// reverse string by mirror image
        for(int i = 0; i < n/2 ; i ++){
            swap(s[i], s[n-1-i]);            
        }
        
        return;
    }
};