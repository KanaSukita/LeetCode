// Implement pow(x, n).


// Example 1:

// Input: 2.00000, 10
// Output: 1024.00000
// Example 2:

// Input: 2.10000, 3
// Output: 9.26100



// Idea;
// use recursion (e.g. 4^4 = (4^2)^2,  4^5 = 4 * (4^2)^2, 4^(-4) = (1/4)^4)

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n==2)
            return x*x;
        if(n%2==0)
            return myPow(myPow(x, n/2), 2);
        if(n<0)
            return myPow(1/x, -n);
        else
            return x * myPow(myPow(x, n/2), 2);
        
    }
};