#include <iostream>
#include <algorithm>
using namespace std;

int dp[100002][5][5], length = 0;
int ins[100001];

int find(int i, int l, int r) {
	if (dp[i][l][r] != 9999999) return dp[i][l][r];
	if (i >= length) return 0;
	int n = ins[i];
	dp[i][l][r] = min(find(i + 1, n, r) + (l == 0 ? 2 : l == n ? 1 : (abs(l - n) % 2 == 0 ? 4 : 3)), find(i + 1, l, n) + (r == 0 ? 2 : r == n ? 1 : (abs(r - n) % 2 == 0 ? 4 : 3)));
	return dp[i][l][r];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	fill(&dp[0][0][0] , &dp[100000][4][5], 9999999);

	int n;

	for (int i = 0; true; i++) {
		cin >> n;
		ins[length] = n;
		if (n == 0) break;
		length++;
	}

	cout << find(0, 0, 0);
	return 0;
}
