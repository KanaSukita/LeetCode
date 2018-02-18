// Given an array of strings, group anagrams together.
//
// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return:
//
// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note: All inputs will be in lower-case.



// Idea:
// use hash map
// for each string in star, sort it and make t, then push it into m[t]
// finally push the vector in m into the res 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, set<string>> m;
        for(auto s:strs){
            string t = s; 
            sort(t.begin(), t.end());
            m[t].insert(s);
        }
        for(auto c:m){
            vector<string> temp(c.second.begin(), c.second.end());
            res.push_back(temp);
        }
        return res;
    }
};