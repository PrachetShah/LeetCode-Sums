class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(char ch){
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        
        // present case
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // absent case
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // RECURSION
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root, word);
    }

    void lcp(string str, string &ans){
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            if(root->childCount == 1){
                ans.push_back(ch);
                // aage badho
                int index = ch-'a';
                root = root->children[index];
            }else{
                break;
            }

            if(root->isTerminal){
                break;
            }
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        // Write your code here
        // using TRIE
//         Trie* t = new Trie('\0');
//         int n = arr.size();
//         // insert all strings in Trie
//         for(int i=0; i<n; i++){
//             t->insertWord(arr[i]);
//         }

//         string first = arr[0];
//         string ans = "";

//         t->lcp(first, ans);
//         return ans;

        // Using Loop Logic
        string ans = "";
        int n = arr.size();

        for(int i=0; i<arr[0].length(); i++){
            char ch = arr[0][i];
            bool match = true;

            for(int j=1; j<n; j++){
                // not match
                if(arr[j].size()<i || ch != arr[j][i]){
                    match = false;
                    break;
                }
            }

            if(match == false){
                break;
            }else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};