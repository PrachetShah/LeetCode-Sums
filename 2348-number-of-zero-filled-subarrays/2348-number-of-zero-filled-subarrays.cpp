class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans = 0, subarray = 0;
        for(auto val: nums){
            if(val == 0){
                subarray++;
            }else{
                subarray = 0;
            }
            ans += subarray;
        }
        return ans;
    }
};