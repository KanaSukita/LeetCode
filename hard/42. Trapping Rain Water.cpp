// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.



// Idea:
// first traverse the array to find the peak and its index
// then traverse from 0 to the peak index, update the level if a higher height appears, otherwise res += level - height[i]
// also traverse from the back to the pead index and do the same thing 

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2)
            return 0;
        int res = 0;
        int peakID, peak = -1;
        for(int i=0;i<height.size();i++){
            if(height[i]>peak){
                peak = height[i];
                peakID = i;
            }
        }
        int level = height[0];
        for(int i=1;i<peakID;i++){
            if(height[i]>level)
                level = height[i];
            else
                res += level - height[i];
        }
        level = height[height.size()-1];
        for(int i=height.size()-2;i>peakID;i--){
            if(height[i]>level)
                level = height[i];
            else
                res += level - height[i];
        }
        return res;
    }
};

