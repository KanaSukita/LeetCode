// Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
// 
// Example1:
// 
// a = 2
// b = [3]
//
// Result: 8
// Example2:
//
// a = 2
// b = [1,0]
// 
// Result: 1024



// Idea:
// use two equations: 
// a^b % 1337 = (a%1337)^b % 1337, 
// xy % 1337 = ((x%1337) * (y%1337)) % 1337
// write a helper function to calculate superPow(int a, int k) for a^k

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) 
            return 1;
        a %= 1337;  
        int temp = b.back();  
        b.pop_back();  
        return (helper(superPow(a, b), 10) * helper(a, temp)) % 1337 ;  
    }
    int helper(int a, int k)  
    {  
        if(!k) 
            return 1;  
        int ans = 1;  
        for(int i = 1; i <= k; i++) ans = (ans*a) %1337;  
        return ans;  
    }  
};