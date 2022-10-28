#include <bits/stdc++.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long int max_so_far = 0, max_total =INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            max_so_far += nums[i];
            
            if(max_total < max_so_far){
                max_total = max_so_far;
            }
            
            if(max_so_far < 0){
                max_so_far = 0;
            }
            // max_total = max(max_total, max_so_far);
        }
        return max_total;
    }
};