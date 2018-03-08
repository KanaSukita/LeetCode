// According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
// 
// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
// 
// Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population..
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// Write a function to compute the next state (after one update) of the board given its current state.
// 
// Follow up: 
// Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
// In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?



// Idea:
// key idea: use the upper bit to represent the next state, write a helper function to find the number of neighbor lives

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty())
            return;
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int life = lives(board, i, j, m, n);
                if(board[i][j] == 1){
                    if(life == 2 || life == 3)
                        board[i][j] = 3;
                }
                else if(!board[i][j] && life == 3)
                    board[i][j] = 2;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                board[i][j] >>= 1;
        }
    }
    int lives(vector<vector<int>>& board, int i, int j, int m, int n){
        int res = -board[i][j];
        for(int r = max(0, i-1);r <= min(i+1, m-1); r++){
            for(int c = max(0, j-1);c<=min(j+1,n-1);c++){
                if(board[r][c] & 1)
                    res++;
            }
        }
        return res;
    }
};