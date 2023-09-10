#include <iostream>
using namespace std;

int weights[31];
int n;
bool dp[31][30001];

void find(int idx, int weight) {
	if (idx > n || dp[idx][weight + 15000]) return;
	dp[idx][weight + 15000] = true;
	find(idx + 1, weight);
	find(idx + 1, weight - weights[idx]);
	find(idx + 1, weight + weights[idx]);
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int m, marble;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> weights[i];

	fill(&dp[0][0], &dp[30][30001], false);

	find(0, 0);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> marble;
		if (marble > 15000)
			cout << 'N' << ' ';
		else
			cout << (dp[n][marble + 15000] == 1 ? 'Y' : 'N') << ' ';
	}

	return 0;
}
