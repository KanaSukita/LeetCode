// This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
// 
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
// 
// word1 and word2 may be the same and they represent two individual words in the list.
// 
// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
// 
// Given word1 = “makes”, word2 = “coding”, return 1.
// Given word1 = "makes", word2 = "makes", return 3.



// Idea:
// use a hash map to store the indices of word1 and word2
// traverse the indices and find the minimum distance, remember to consider the condition when the two words are the same by adding a condition when the indices are the same

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> m;
        for(int i=0;i<words.size();i++)
            m[words[i]].push_back(i);
        int i = 0, j = 0, res = INT_MAX;
        while(i < m[word1].size() && j < m[word2].size()){
            if(m[word1][i] != m[word2][j])
                res = min(res, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j]? i++ : j++;
        }
        return res;
    }
};