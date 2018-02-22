// A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.
// 
// What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.
// 
// Examples:
// Input: A = [1, 2, 3, 5], K = 3
// Output: [2, 5]
// Explanation:
// The fractions to be considered in sorted order are:
// 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
// The third fraction is 2/5.
//
// Input: A = [1, 7], K = 1
// Output: [1, 7]
// Note:
//
// A will have length between 2 and 2000.
// Each A[i] will be between 1 and 30000.
// K will be between 1 and A.length * (A.length + 1) / 2.



// Idea:
// use priority queue which store pair<double, vector<int>>
// for [1, 2, 3, 5], build map as below, put the first col first, each time pop an elemnt, put the next element in the same row
// 1/5  1/3  1/2
// 2/5  2/3
// 3/5

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n = A.size();
        priority_queue<pair<double, vector<int>>> pq;
        for(int i=0;i<n-1;i++)
            pq.push(make_pair(-1.0*A[i]/A.back(), vector<int>{i, n-1}));
        while(--K >= 1){
            auto temp = pq.top().second;
            pq.pop();
            temp[1]--;
            pq.push(make_pair(-1.0*A[temp[0]]/A[temp[1]], vector<int>{temp[0], temp[1]}));
        }
        vector<int> res = pq.top().second;
        return {A[res[0]], A[res[1]]};
    }
};



