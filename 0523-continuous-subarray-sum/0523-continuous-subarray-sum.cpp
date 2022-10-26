class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap{{0, 0}};
        
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(!hashMap.count(sum%k)){
                hashMap[sum%k] = i+1;
            }else if(hashMap[sum%k] < i){
                return true;
            }
        }
        return false;
    }
};