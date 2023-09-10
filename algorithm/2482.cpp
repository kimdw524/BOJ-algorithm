#include <iostream>
using namespace std;

int dp[1001][1001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	fill(&dp[0][0], &dp[1000][1001], 0);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			if (i == n)
				dp[i][j] = dp[i - 3][j - 1] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j];
			dp[i][j] %= 1000000003;
		}
	}

	cout << dp[n][k];

	return 0;
}
