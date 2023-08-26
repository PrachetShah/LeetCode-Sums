class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        
        int left=0, right=height.size()-1;
        
        while(left < right){
            int temp = min(height[left], height[right])*(right-left);
            area = max(temp, area);
            if(height[left] > height[right]){
                right--;
            }else{
                left++;
            }
        }

        return area;
    }
};