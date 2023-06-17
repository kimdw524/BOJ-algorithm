#include <iostream>
using namespace std;

int arr[1000][1000];
int dp[1000][1000][3];
int n, m;

int solve(int y, int x, int direction) {
	if (dp[y][x][direction] != -999999) return dp[y][x][direction];
	if (y == n - 1) {
		dp[y][x][direction] = 0;
		for (int i = x; i < m; i++)
			dp[y][x][direction] += arr[n - 1][i];
	} else {
		int max = solve(y + 1, x, 0);
		if (direction != 1 && x < m - 1)
			max = std::max(max, solve(y, x + 1, 2));
		if (direction != 2 && x > 0)
			max = std::max(max, solve(y, x - 1, 1));
		dp[y][x][direction] = max + arr[y][x];
	}
	return dp[y][x][direction];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	fill(&dp[0][0][0], &dp[1000][1000][3], -999999);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	solve(0, 0, 0);
	
	cout << max(dp[0][0][2], max(dp[0][0][0], dp[0][0][1]));
	return 0;
}
