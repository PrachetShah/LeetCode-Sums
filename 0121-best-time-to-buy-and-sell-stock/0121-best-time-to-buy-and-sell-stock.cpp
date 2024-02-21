class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minProfit = INT_MAX;
        int maxProfit = 0;
        for(auto price: prices){
            if(price < minProfit){
                minProfit = price;
            }else if(price-minProfit > maxProfit){
                maxProfit = price-minProfit;
            }
        }
        return maxProfit;
    }
};