class Solution {
    public int numberOfSteps(int num) {
        int steps = 0;
        while(num!=0){
            if(num%2==0){
                num = num/2;
                steps += 1;
            }else{
                num = num - 1;
                steps += 1;
            }
        }
        return steps;
    }
}