// LeetCode wants to give one of its best employees the option to travel among N cities to collect algorithm problems. 
// But all work and no play makes Jack a dull boy, you could take vacations in some particular cities and weeks. Your job is
// to schedule the traveling to maximize the number of vacation days you could take, but there are certain rules and restrictions
// you need to follow.

// Rules and restrictions:
// You can only travel among N cities, represented by indexes from 0 to N - 1. Initially, you are in the city indexed 0 on Monday.
// The cities are connected by flights.The flights are represented as a N*N matrix(not necessary symmetrical), called flights representing 
// the airline status from the city i to the city j.If there is no flight from the city i to the city j, flights[i][j] = 0; Otherwise, 
// flights[i][j] = 1. Also, flights[i][i] = 0 for all i.
// You totally have K weeks(each week has 7 days) to travel.You can only take flights at most once per day and can only take flights on each 
// week's Monday morning. Since flight time is so short, we don't consider the impact of flight time.
// For each city, you can only have restricted vacation days in different weeks, given an N*K matrix called days representing this relationship.
// For the value of days[i][j], it represents the maximum days you could take vacation in the city i in the week j.
// You're given the flights matrix and days matrix, and you need to output the maximum vacation days you could take during K weeks.



// Idea:
// using the method of dp
// dp[i][j] as vacation days until j week which ends up staying in cities i
// when computing the maximizer, if dp[l][j - 1] == 0 means it's un reachable 

class Solution {
public:
	int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
		int n = flights.size(), k = days[0].size(), res = 0;
		vector<vector<int>> dp(n, vector<int>(k, -1));
		dp[0][0] = days[0][0];
		for (int i = 1; i<n; i++) {
			if (flights[0][i] == 1)
				dp[i][0] = days[i][0];
		}
		for (int i = 1; i<k; i++) {
			for (int j = 0; j<n; j++) {
				for (int m = 0; m<n; m++) {
					if ((flights[m][j] == 1 || m == j) && dp[m][i - 1] != -1)
						dp[j][i] = max(dp[m][i - 1] + days[j][i], dp[j][i]);
				}
			}
		}
		for (int i = 0; i<n; i++) res = max(res, dp[i][k - 1]);
		return res;
	}
};