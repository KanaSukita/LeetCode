// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
// 
// Example 1:
// Input: "aba"
// Output: True
// Example 2:
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.
// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 50000.



// Idea:
// use two pointers l and r, first find the most l and least r that s[l] != s[r]
// then write a helper function to find if l+1 to r or l to r-1 can form a palindrome

class Solution {
public:
    bool validPalindrome(string s) {
        int l=0, r = s.length()-1;
        while(s[l] == s[r] && l < r){
            l++;
            r--;
        }
        return helper(l+1, r ,s) || helper(l, r-1, s);
    }
    bool helper(int l, int r, string &s){
        while(s[l] == s[r] && l< r){
            l++;
            r--;
        }
        return l >= r;
    }
};