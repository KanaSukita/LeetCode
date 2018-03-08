// Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
// 
// Example 1:
// Input:
// s = "abpcplea", d = ["ale","apple","monkey","plea"]
// 
// Output: 
// "apple"
// Example 2:
// Input:
// s = "abpcplea", d = ["a","b","c"]
// 
// Output: 
// "a"



// Idea:
// use two pointers, traverse all the words in the dictionary, save word as ans if the three conditions are met: 
//v1. k==n: if every letter of word exists in string s (and in order of the word)
// 2. res.length()<n: word is a longer word than res
// 3. (res.length()==n && res>word): word is same size as ans but is lexicographically smaller

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for(string w : d){
            int i = 0, j = 0, n = w.length();
            while(i < s.length() && j < n){
                if(s[i] == w[j])
                    j++;
                i++;
            }
            if(j == n && ((res.length() == n && res > w) || res.length() < n))
               res = w;
        }
        return res;
    }
};