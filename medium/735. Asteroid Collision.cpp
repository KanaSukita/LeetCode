// We are given an array asteroids of integers representing asteroids in a row.
// 
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// 
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
// 
// Example 1:
// Input: 
// asteroids = [5, 10, -5]
// Output: [5, 10]
// Explanation: 
// The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
// Example 2:
// Input: 
// asteroids = [8, -8]
// Output: []
// Explanation: 
// The 8 and -8 collide exploding each other.
// Example 3:
// Input: 
// asteroids = [10, 2, -5]
// Output: [10]
// Explanation: 
// The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.
// Example 4:
// Input: 
// asteroids = [-2, -1, 1, 2]
// Output: [-2, -1, 1, 2]
// Explanation: 
// The -2 and -1 are moving left, while the 1 and 2 are moving right.
/// Asteroids moving the same direction never meet, so no asteroids will meet each other.



// Idea:
// use a stack to store the asteroids
// when a new asteriod smaller than 0 and the stack is not empty, compare it with the top of the stack

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> s;
        for(int a : asteroids){
            while(!s.empty() && a < 0 && s.top() > 0){
                if(-a > s.top())
                    s.pop();
                else if(-a == s.top()){
                    a =0;
                    s.pop();
                    break;
                }
                else{
                    a = 0;
                    break;
                }
            }
            if(a == 0)
                continue;
            else
                s.push(a);
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};