// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

// For example, given the range [5, 7], you should return 4.



// Idea:
// use the method of bit manipulation, the problem is to find the common bits of m and n, so we right shift m and n until they are the same, And finally we return the same part by shifting left the same times.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        while(m != n){
            i++;
            m >>= 1;
            n >>= 1;
        }
        return (n<<i);
    }
};