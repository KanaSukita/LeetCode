// Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement: 
// Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

// If there are multiple answers, print any of them.

// Example 1:
// Input: n = 3, k = 1
// Output: [1, 2, 3]
// Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
// Example 2:
// Input: n = 3, k = 2
// Output: [1, 3, 2]
// Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.



// Idea:
// array manipulation, for k dis, sort it as 1, k+1, 2, k, 3, k-1, ..., k+2, k+3, ..., n

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int l = 1, r = k + 1;
        while(l<=r){
            res.push_back(l++);
            if(l <= r)
                res.push_back(r--);
        }
        for(int i=k+2;i<=n;i++)
            res.push_back(i);
        return res;
    }
};