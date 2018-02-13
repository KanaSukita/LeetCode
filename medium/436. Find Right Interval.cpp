// Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

// For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

// Note:
// You may assume the interval's end point is always bigger than its start point.
// You may assume none of these intervals have the same start point.
// Example 1:
// Input: [ [1,2] ]

// Output: [-1]

// Explanation: There is only one interval in the collection, so it outputs -1.



// Idea:
// use the method of map, where m[invervals[i]] = i
// then traverse the intervals again, if m.lower_bound(i.end) can be found, res[i] = it->second;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        int n = intervals.size();
        map<int, int> m;
        vector<int> res;
        for(int i=0;i<n;i++)
            m[intervals[i].start] = i;
        for(auto i:intervals){
            auto it = m.lower_bound(i.end);
            if(it == m.end())
                res.push_back(-1);
            else
                res.push_back(it->second);
        }
        return res;
    }
};