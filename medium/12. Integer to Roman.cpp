// Given an integer, convert it to a roman numeral.

// Input is guaranteed to be within the range from 1 to 3999.



// Idea:
// write a dictionary and use it to form the roman

class Solution {
public:
    string intToRoman(int num) {
        vector<string> dict = {"","I","II","III","IV","V","VI","VII","VIII","IX",
                                "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                                "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                                "","M","MM","MMM","MMMM"};
        return dict[num/1000+30]+dict[(num/100)%10+20]+dict[(num/10)%10+10]+dict[num%10];
    }
};