class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> arr;
        for(auto num: nums){
            arr.push_back(num-rev(num));
        }
        
        unordered_map<int, int> dic;
        int ans=0, MOD=1e9+7;
        
        for(auto num: arr){
            ans = (ans+dic[num])%MOD;
            dic[num]++;
        }
        
        return ans;
    }
    
    int rev(int num){
        int result = 0;
        while(num > 0){
            result = result*10 + num%10;
            num /= 10;
        }
        
        return result;
    }
};