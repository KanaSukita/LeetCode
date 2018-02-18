// Special binary strings are binary strings with the following two properties:
// 
// The number of 0's is equal to the number of 1's.
// Every prefix of the binary string has at least as many 1's as 0's.
// Given a special string S, a move consists of choosing two consecutive, non-empty, special substrings of S, and swapping them. (Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.)
//
// At the end of any number of moves, what is the lexicographically largest resulting string possible?
//
// Example 1:
// Input: S = "11011000"
// Output: "11100100"
// Explanation:
// The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
// This is the lexicographically largest string possible after some number of swaps.
// Note:
//
// S has length at most 50.
// S is guaranteed to be a special binary string as defined above.



// Idea:
// use recursion
// split S into as many special strings as possible, while each speacial string can be written as 1 ....  0, recursion of the middle part. Sort all special strings in lexicographically largest order. Join and output all strings.

class Solution {
public:
    string makeLargestSpecial(string S) {
        int cnt = 0, cur = 0;
        vector<string> temp;
        string res = "";
        for(int i=0;i<S.length();i++){
            if(S[i] == '1')
                cnt++;
            else
                cnt--;
            if(!cnt){
                temp.push_back("1" + makeLargestSpecial(S.substr(cur+1, i - cur)) + "0");
                cur = i + 1;
            }
        }
        sort(temp.begin(), temp.end(), greater<string> ());
        for(auto t:temp)
            res += t;
        return res;
    }
};
