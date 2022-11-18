class Solution {
public:
    int dividing(int dividend, int divisor){
        while(dividend%divisor==0){
            dividend = (int)dividend/divisor;
        }
        return dividend;
    }
    bool isUgly(int n) {
        if(n<=0){
            return false;
        }
        for(auto factor: {2,3,5}){
            n = dividing(n, factor);
        }
        
        return n==1;
        
    }
};