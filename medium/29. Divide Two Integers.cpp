// Divide two integers without using multiplication, division and mod operator.

// If it is overflow, return MAX_INT.



// Idea:
// left shift divisor and a res_temp to represent times
// dividend minus the left-shifted divisor and add the times 

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend > 0) ^ (divisor > 0))? -1: 1;
        int res = 0;
        long long d1 = labs(dividend), d2 = labs(divisor);
        while(d1 >= d2){
            long long temp = d2, res_temp = 1;
            while((temp<<1) <= d1){
                temp<<=1;
                res_temp<<=1;
            }
            res += res_temp;
            d1 -= temp;
        }
        return (res > INT_MAX)? INT_MAX : res * sign;
    }
};