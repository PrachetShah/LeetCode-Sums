class Solution {
public:
    void reverseString(vector<char>& s) {
        
        size_t n = s.size();
        
		// reverse string by mirror image
        for( size_t i = 0; i < n/2 ; i ++){
		
            swap(s[i], s[n-1-i]);            
        }
        
        return;
    }
};