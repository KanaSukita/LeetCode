// In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Those answers are placed in an array.

// Return the minimum number of rabbits that could be in the forest.

// Examples:
// Input: answers = [1, 1, 2]
// Output: 5
// Explanation:
// The two rabbits that answered "1" could both be the same color, say red.
// The rabbit than answered "2" can't be red or the answers would be inconsistent.
// Say the rabbit that answered "2" was blue.
// Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
// The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

// Input: answers = [10, 10, 10]
// Output: 11

// Input: answers = []
// Output: 0



// Idea:
// using hash map(or simply a vector with 1000 size in this one), count the times of a number, when there are n+1 rabbits said n, they can be in the same class, when m[n] > n+1, use the same method for the extra

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> m(1000, 0);
        for(int n:answers)
            m[n]++;
        int res = m[0];
        for(int i = 1;i<1000;i++){
            if(!m[i])
                continue;
            if(m[i]<=i+1)
                res += (i+1);
            else{
                while(m[i] > 0){
                    res += (i+1);
                    m[i] -= (i+1); 
                }
            }
        }
        return res;
    }
};