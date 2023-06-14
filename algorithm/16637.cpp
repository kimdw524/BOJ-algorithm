#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

vector<int> num;
vector<char> op;

long ans = -pow(2,31);

long calc(long a, long b, char o) {
	switch (o) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
}

void find(long c, int n) {
	if (n + 1 >= num.size()) {
		ans = max(c, ans);
		return;
	}
	
	find(calc(c, num[n + 1], op[n]), n + 1);

	if(n + 2 < num.size())
		find(calc(c, calc(num[n+1], num[n + 2], op[n + 1]), op[n]), n + 2);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	string expression;
	cin >> n;
	cin >> expression;
	
	for (int i = 0; i < expression.size(); i++) {
		if (i % 2 == 0)
			num.push_back((int)expression.at(i) - '0');
		else
			op.push_back(expression.at(i));
	}

	find(num[0], 0);
	cout << ans;
	return 0;
}
