// There are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements :

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.



// Idea:
// traverse the array twice, first time to let candies[i+1] > candies[i] if ratings[i+1] > ratings[i], 
// second time to let candies[i] > candies[i+1] if ratings[i] > ratings[i+1] 

class Solution {
public:
	int candy(vector<int>& ratings) {
		if (!ratings.size())
			return 0;
		int n = ratings.size();
		vector<int> candies(n, 1);
		for (int i = 1; i<n; i++) {
			if (ratings[i] > ratings[i - 1])
				candies[i] = candies[i - 1] + 1;
		}
		int res = candies[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
				candies[i] = max(candies[i], candies[i + 1] + 1);
			res += candies[i];
		}
		return res;
	}
};