// Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
// An empty string is also valid.
// Example 1:
// Input: "()"
// Output: True
// Example 2:
// Input: "(*)"
// Output: True
// Example 3:
// Input: "(*))"
// Output: True



// Idea:
// use two stacks to store the index of left and star
// when a right appears, chech first if the left stack is empty, then the star stack
// and finally, check if the index the left are smaller than the star

class Solution {
public:
    bool checkValidString(string s) {
        if(s.empty())
            return true;
        stack<char> left, star;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(')
                left.push(i);
            else if(s[i] == '*')
                star.push(i);
            else{
                if(left.empty()){
                    if(star.empty())
                        return false;
                    else
                        star.pop();
                }
                else
                    left.pop();
            }
        }
        while(!left.empty() && !star.empty()){
            if(left.top() > star.top())
                return false;
            left.pop();
            star.pop();
        }
        return left.empty();
    }
};