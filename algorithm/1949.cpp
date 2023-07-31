#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int population[10001];
int dp[10001][2];
vector<int> tree[10001];

int find(int n, bool b, bool prev, int p) {
	int res = 0;
	if (dp[n][b] != -1) return dp[n][b];
	if (b) {
		for (int i : tree[n]) {
			if (i == p) continue;
			res += find(i, false, b, n);
		}
		dp[n][b] = res + population[n];
	} else {
		for (int i : tree[n]) {
			if (i == p) continue;
			res += max(find(i, false, b, n), find(i, true, b, n));
		}
		dp[n][b] = res;
	}
	return dp[n][b];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	fill(&dp[0][0], &dp[10000][2], -1);

	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> population[i];

	int n1, n2;

	for (int i = 0; i < n - 1; i++) {
		cin >> n1 >> n2;
		tree[n1].emplace_back(n2);
		tree[n2].emplace_back(n1);
	}

	cout << max(find(1, false, false, -1), find(1, true, false, -1)) << endl;

	return 0;
}
