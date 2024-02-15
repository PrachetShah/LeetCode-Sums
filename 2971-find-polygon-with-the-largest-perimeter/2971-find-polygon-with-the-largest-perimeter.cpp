class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long int prevSum = 0;
        long long int ans = -1;
        for(auto num: nums){
            if(num < prevSum){
                ans = num + prevSum;
            }
            prevSum += num;
        }
        return ans;
    }
};