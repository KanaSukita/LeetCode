// Write a function to find the longest common prefix string amongst an array of strings.



// Idea:
// sort the array of string, compare the first one with the last one and find prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        if(strs.size()==0)
            return res;
        if(strs.size()==1)
            return strs[0];
        sort(strs.begin(),strs.end());
        int i = 0;
        while(strs[0][i]==strs[strs.size()-1][i] && i<strs[0].size()){
            res = res + strs[0][i];
            i++;
        }
        return res;
    }
};