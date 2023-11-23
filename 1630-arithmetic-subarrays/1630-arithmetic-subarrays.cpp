class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); i++){
            vector<int> check(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(check.begin(), check.end());
            
            bool flag = false;
            for(int j=1; j< check.size(); j++){
                if(check[j]-check[j-1] == check[1] - check[0]){
                    continue;
                }else{
                    flag = true;
                    ans.push_back(false);
                    break;
                }
            }
            if(!flag){
                ans.push_back(true);
            }
            // cout << "\n";
        }
        return ans;
    }
};