// There are N network nodes, labelled 1 to N.

// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node,
// and w is the time it takes for a signal to travel from source to target.

// Now, we send a signal from a certain node K.How long will it take for all nodes to receive the signal ? If it is impossible, return -1.

// Note :
//	  N will be in the range[1, 100].
//	  K will be in the range[1, N].
//	  The length of times will be in the range[1, 6000].
//	  All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.



// Idea:
// first thought:
// using the method of Bellman Ford, after n - 1 times of augments there will not a any new path(when the weight of the edge is non - negative).

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<int> wait(N + 1, INT_MAX);
		wait[K] = 0;
		for (int i = 1; i <= N - 1; i++) {
			for (auto t : times) {
				int u = t[0], v = t[1], w = t[2];
				if (wait[u] != INT_MAX && wait[u] + w < wait[v])
					wait[v] = wait[u] + w;
			}
		}
		int res = INT_MIN;
		for (int i = 1; i<N + 1; i++)
			res = max(res, wait[i]);
		return res == INT_MAX ? -1 : res;
	}
};
