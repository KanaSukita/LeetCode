// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.



// Idea:
// using the method of greedy
// to avoid a loop within another loop, link the two loops to one loop, if the sum < 0, just start the next index with a sum = 0 and continue. 
// If the start index is greater than n, that means we have tried all the possibilities and return -1


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), sum = 0, res = 0;
        for(int i=0;i<n;i++)
            gas[i] -= cost[i];
        for(int i=0;i<n*2-1;i++){
            sum += gas[i%n];
            if(sum < 0){
                res = i + 1;
                if(res >= n)
                    return -1;
                sum = 0;
            }
        }
        return res;
    }
};