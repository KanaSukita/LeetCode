// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
// 
// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
// Example 1:
//
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:
// 
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:
//
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.



// Idea:
// use greedy
// if  the new number is smaller than the previous one, delete the previous one

class Solution {  
public:  
    string removeKdigits(string num, int k) {  
        string ans;  
        int n = k, len = num.size(), cnt = 0;  
        for(auto val: num)  
        {  
            while(!ans.empty() && n > 0 && val < ans.back())  
            {  
                n--;  
                ans.pop_back();  
            }  
            ans.push_back(val);  
        }  
        while(ans[cnt]=='0') cnt++;  
        ans = ans.substr(cnt, len-k-cnt);  
        return !ans.size()?"0":ans;  
    }  
}; 