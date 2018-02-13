// Given a string, find the length of the longest substring without repeating characters.

// Examples:

// Given "abcabcbb", the answer is "abc", which the length is 3.

// Given "bbbbb", the answer is "b", with the length of 1.

// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.



// Idea:
// Using the template
// a variable count to represent the times of repeatence.
// when repeatence holds, increase begin
// update d when (end - begin) > d

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m (128, 0);
        int count = 0, begin = 0, end = 0, d = 0;
        while(end < s.length()){
            if(m[s[end++]]++ > 0)
                count++;
            while(count > 0){
                if(m[s[begin++]]-- > 1)
                    count--;
            }
            d = max(d, end - begin);
        }
        return d;
    }
};