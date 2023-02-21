//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {

        // USING MAP
        /* map<char, int> counter;
        
        // for(int i=0; i<str.size(); i++){
        //     counter[str[i]]++;
        // }
        
        // int max = 0;
        // char temp;
        // for(auto count : counter){
        //     if(count.second > max){
        //         max = count.second;
        //         temp = count.first;
        //     }
        // }
        
        return temp;
        */
        
        // USING ARRAY
        vector<int> hash(26, 0);
        for(auto s: str){
            hash[s-'a']++;
        }
        int maxi=0;
        char temp;
        
        for(int i=0; i<26; i++){
            if(hash[i] > maxi){
                maxi = hash[i];
                temp = i + 'a';
            }
        }
        return temp;
        
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends
