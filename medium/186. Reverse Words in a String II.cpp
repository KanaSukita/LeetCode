// Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
// 
// The input string does not contain leading or trailing spaces and the words are always separated by a single space.
//
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".
// 
// Could you do it in-place without allocating extra space?
//
// Related problem: Rotate Array



// Idea:
// reverse the sholw srting first, then try to find the blank and reverse eah word

class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int l = 0, r = 0, n = str.size();
        while(r < n){
            while(r < n && str[r] != ' ')
                r++;
            reverse(str.begin()+l, str.begin()+r);
            l = ++r;
        }
    }
};