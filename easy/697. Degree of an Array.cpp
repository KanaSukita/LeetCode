// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

//Example 1:
// Input: [1, 2, 2, 3, 1]
// Output: 2
// Explanation: 
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.
// Example 2:
// Input: [1,2,2,3,1,4,2]
// Output: 6



// Idea:
// use two hash map, one to store the frequencies and the other to be used to store the start index, when the count is larger than fre, update the new length as i - start[nums[i]] + 1, when it's equal, compare the length and use the shorter one

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), fre = 0, res = INT_MAX;
        if(n < 2)
            return n;
        unordered_map<int, int> start, count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
            if(count[nums[i]] == 1)
                start[nums[i]] = i;
            if(count[nums[i]] > fre){
                res = i - start[nums[i]] + 1;
                fre = count[nums[i]];
            }
            else if(count[nums[i]] == fre)
                res = min(res, i - start[nums[i]] + 1);
        }
        return res;
    }
};
