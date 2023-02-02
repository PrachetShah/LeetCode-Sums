class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> ans;
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(ans.find(diff) != ans.end()){
                result.push_back(ans[diff]);
                result.push_back(i);
                return result;
            }
            ans[nums[i]] = i;
        }
        return result;
    }
};
