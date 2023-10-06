class Solution {
public:
    vector<int> memo;
    
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        memo = vector(n + 1, 0);
        return dp(n);
    }
    
    int dp(int num) {
        if (num <= 3) {
            return num;
        }
        
        if (memo[num] != 0) {
            return memo[num];
        }
        
        int ans = num;
        for (int i = 2; i < num; i++) {
            ans = max(ans, i * dp(num - i));
        }
        
        memo[num] = ans;
        return ans;
    }
};