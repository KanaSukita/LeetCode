// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
// 
// For example,
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3



// Idea:
// use a queue with size size

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        s = size;
    }
    
    double next(int val) {
        if(pq.size() == s)
            pq.pop();
        pq.push(val);
        double res = 0;
        for(int i=0;i<pq.size();i++){
            int temp = pq.front();
            res += temp;
            pq.pop();
            pq.push(temp);
        }
        return res / pq.size();
    }
private:
    queue<int> pq;
    int s;
};
