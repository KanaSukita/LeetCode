// We are given a list schedule of employees, which represents the working time for each employee.

// Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

// Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

// Example 1:
// Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
// Output: [[3,4]]
// Explanation:
// There are a total of three employees, and all common
// free time intervals would be [-inf, 1], [3, 4], [10, inf].
// We discard any intervals that contain inf as they aren't finite.
// Example 2:
// Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
// Output: [[5,6],[7,9]]



// Idea:
// use the method of greedy and priority queue, let the interval with the smaller start time be placed in front
// pop the interval and maintain a cur_end time, when a new start time is smaller than the cur_end, it means interval [cur_end, start] is a mutual free interval, because the intervals behind will all have a larger start time

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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> res;
        priority_queue<Interval, vector<Interval>, cmp> pq;
        for(int i=0;i<schedule.size();i++){
            for(int j=0;j<schedule[i].size();j++){
                pq.push(schedule[i][j]);
            }
        }
        Interval cur = pq.top();
        pq.pop();
        int cur_end = cur.end;
        while(!pq.empty()){
            Interval cur = pq.top();
            pq.pop();
            if(cur_end < cur.start)
                res.push_back(Interval(cur_end, cur.start));
            cur_end = max(cur_end, cur.end);
        }
        return res;
    }
    struct cmp{
        bool operator()(const Interval &a, const Interval &b){
            if(a.start == b.start)
                return a.end > b.end;
            return a.start > b.start;
        }
    };