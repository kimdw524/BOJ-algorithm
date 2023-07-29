#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int d[51][51];
int dp[51][51];
bool visited[51][51];
int n, m;

int find(int y, int x) {
	if (d[y][x] == -1) return 0;
	if (dp[y][x] > -1) return dp[y][x];
	int res = 0;
	if (visited[y][x]) {
		cout << -1 << endl;
		exit(0);
	}
	visited[y][x] = true;
	if (y - d[y][x] >= 0)
		res = max(res, find(y - d[y][x], x));
	if (y + d[y][x] < n)
		res = max(res, find(y + d[y][x], x));
	if (x - d[y][x] >= 0)
		res = max(res, find(y, x - d[y][x]));
	if (x + d[y][x] < m)
		res = max(res, find(y, x + d[y][x]));
	dp[y][x] = res + 1;
	
	return dp[y][x];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	fill(&dp[0][0], &dp[50][51], -1);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < t.size(); j++)
			d[i][j] = (t[j] == 'H') ? -1 : (t[j] -'0');
	}

	cout << find(0, 0);

	return 0;
}
