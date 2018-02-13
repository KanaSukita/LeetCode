// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]



// Idea:
// use backtracking
// in detail, write a helper function to serve for recusion

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addPar(res, "", 0, 0, n);
        return res;
    } 
    void addPar(vector<string> &res, string cur, int left, int right, int n){
        if(cur.length()==n*2){
            res.push_back(cur);
            return;
        }
        if(left<n)
            addPar(res, cur+"(", left+1, right, n);
        if(right<n && right<left)
            addPar(res, cur+")", left, right+1, n);
    }
};