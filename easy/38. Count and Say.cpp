// The count-and-say sequence is the sequence of integers with the first five terms as following:

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth term of the count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string.

// Example 1:

// Input: 1
// Output: "1"
// Example 2:

// Input: 4
// Output: "1211"



// Idea:
// some kind of brute force
// compute the result for each time, use a counter and cur to store the current number

class Solution {
public:
    string countAndSay(int n) {
        if(n==0)
            return "";
        string res = to_string(1);
        while(--n){
            string cur ="";
            for(int i=0;i<res.size();i++){
                int count = 1;
                while((i+1<res.size()) && (res[i] == res[i+1])){
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};