class Solution {
public:
    int climbStairs(int n) {        
        vector<int> ans(n, 0);
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        ans[0] = 1;
        ans[1] = 2;
        
        // recusrive call
        for(int i=2; i<n; i++){
            ans[i] = ans[i-1] + ans[i-2];
        }
        
        return ans[n-1];
    }
};