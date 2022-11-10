class Solution {
public:
    string removeDuplicates(string s) {
        int len = s.length()-1;
        int i = 0;
        while(i < len)
        {
            // cout<<i<<endl;
            if(s.at(i) == s.at(i+1))
            {
                if(i == 0)
                {
                    s.erase(0,2);
                }
                else
                {
                    s.erase(i,2);
                    i--;
                }
                len = s.length()-1;
            }
            else
                i++;
        }
       
        return s;
    }
};