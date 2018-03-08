// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
// Example 1:
// Input:s1 = "ab" s2 = "eidbaooo"
// Output:True
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False



// Idea:
// use sliding window, first use a map to store the char of s1, along with a integer cnt to represent the number.
// scan the string s2, if(m[s2[right]]-- > 0), make cnt--
// when cnt == 0, check if right - left  + 1 == n1, otherwise, make ++m[s2[left++]], and cnt++

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), cnt = n1, left = 0;
        vector<int> m(128);
        for (char c : s1) ++m[c];
        for (int right = 0; right < n2; ++right) {
            if (m[s2[right]]-- > 0) --cnt;
            while (cnt == 0) {
                if (right - left + 1 == n1) return true;
                if (++m[s2[left++]] > 0) ++cnt;
            }
        }
        return false;
    }
};
