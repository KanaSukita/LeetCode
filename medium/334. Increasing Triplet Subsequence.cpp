// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
// 
// Formally the function should:
// Return true if there exists i, j, k 
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Your algorithm should run in O(n) time complexity and O(1) space complexity.
// 
// Examples:
// Given [1, 2, 3, 4, 5],
// return true.
// 
// Given [5, 4, 3, 2, 1],
// return false.



// Idea:
// traverse from the back, use a second and largest, when nums[i] > largest, update the new largest number, when nums[i] < largest && nums[i] > second, update the second largest number, when nums[i] < second, return true

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int second = INT_MIN, n = nums.size()-1;
        if(n < 3)
            return false;
        int largest = nums[n];
        for(int i=n-1; i>=0; i--){
            if(nums[i] > largest){
                largest = nums[i];
            }
            else if(nums[i] < largest && nums[i] > second){
                second = nums[i];
            }
            else if(nums[i] < second)
                return true;
        }
        return false;
    }
};