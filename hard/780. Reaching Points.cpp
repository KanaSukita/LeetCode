// A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).

// Given a starting point (sx, sy) and a target point (tx, ty), return True if and only if a sequence of moves exists to transform the point (sx, sy) to (tx, ty). Otherwise, return False.

// Examples:
// Input: sx = 1, sy = 1, tx = 3, ty = 5
// Output: True
// Explanation:
// One series of moves that transforms the starting point to the target is:
// (1, 1) -> (1, 2)
// (1, 2) -> (3, 2)
// (3, 2) -> (3, 5)

// Input: sx = 1, sy = 1, tx = 2, ty = 2
// Output: False

// Input: sx = 1, sy = 1, tx = 1, ty = 1
// Output: True



// Idea:
// if sx == tx or sy == ty, check if the difference between s and t is a times of the other s(prevent from TLE)
// we can check from the back, when tx > ty, tx -= ty, and ty -= tx otherwise. Finally we check if tx == sx and ty == sy

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx == tx)
            return ((ty-sy) % tx == 0);
        if(sy == ty)
            return ((tx-sx) % ty == 0);
        while(tx > sx || ty > sy){
            if(tx < sx || ty < sy)
                return false;
            if(tx>ty)
                tx -= ty;
            else
                ty -= tx;
        }
        if(tx == sx && ty == sy)
            return true;
        return false;
    }
};