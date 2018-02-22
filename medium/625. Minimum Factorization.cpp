// Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.
//
// If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.
// 
// Example 1
// Input:
// 
// 48 
// Output:
// 68
// Example 2
// Input:
//
// 15
// Output:
// 35



// Idea:
// traverse the possible digits from 9 to 2, put the new factor in the upper digits, also check if it exceed INT_MAX 
// check if the final a==1, if it's not, then no such digit exist

class Solution {
public:
    int smallestFactorization(int a) {
        if(a < 10)
            return a;
        long long res = 0, digit = 1;
        for(int i=9;i>=2;i--){
            while(a % i == 0){
                res += i * digit;
                digit *= 10;
                a /= i;
                if(res > INT_MAX)
                    return 0;
            }
        }
        return a == 1? res : 0;
    }
};