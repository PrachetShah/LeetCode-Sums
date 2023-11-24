class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int answer = 0;
        
        for(int i=piles.size()/3; i<piles.size(); i+=2){
            answer += piles[i];
        }
        
        return answer;
    }
};