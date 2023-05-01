class Solution {
public:
    double average(vector<int>& salary) {
        int max= salary[0];
        int min = salary[0];
        int sum = 0;
        for(int i=0; i<salary.size(); i++){
            if(salary[i] > max){
                max = salary[i];
            }
            if(salary[i] < min){
                min = salary[i];
            }
            sum += salary[i];
        }
        cout << "MIN: "<<min<<" MAX:"<<max<<endl;
        double avg = (double)(sum-max-min)/(salary.size()-2);
        return avg;
    }
};