class Solution {
public:
    bool isPalindrome(int x) {
        long long int temp = 0;
        long long int ogi = x;
        while(x > 0){
            temp = temp*10 + x%10;
            x = x/10;
        }

        return temp == ogi;
    }
};