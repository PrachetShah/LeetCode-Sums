class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> m;
        if(nums.empty())return {};
        
        vector<int> ans;
        for(auto n: nums){
            m[n]++;
        }
        
        for(auto n: m){
            if(n.second==2){
                ans.push_back(n.first);
            }
        }
        return ans;
    }
};