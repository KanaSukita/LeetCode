// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".



// Idea:
// create a string vector to represent each row, use a integer step to represent the the relaition  between the cur and the next row and decide which row the next character belongs

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) 
            return s;
        vector<string> p(numRows,"");
        int size=2*numRows-2;
        for(int i=0;i<s.size();i++) p[abs(numRows-1-i%size)]+=s[i];
        return accumulate( p.rbegin(), p.rend(), string("") );
    }
};

