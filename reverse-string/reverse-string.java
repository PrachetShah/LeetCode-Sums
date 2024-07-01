class Solution {
    public void reverseString(char[] s) {
        int n = s.length;
        for(int i=0; i<s.length/2; i++){
            // using a temp third var
            /*
            char temp = s[i];
            s[i] = s[s.length-i-1];
            s[s.length-i-1] = temp;
            */
            
            // swapping using xor
            s[i] = (char) (s[i]^s[n-i-1]);
            s[n-i-1] = (char) (s[i]^s[n-i-1]);
            s[i] = (char) (s[i]^s[n-i-1]);
        }
    }
}