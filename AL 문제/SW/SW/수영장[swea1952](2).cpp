#include <iostream>
#include <algorithm>
using namespace std;
/*
	¼ö¿µÀå
*/
int i, j, t, T, result;
int d, m, m3, y;
int dp[15];

void input()
{
	cin >> d >> m >> m3 >> y;
}

void cal()
{
	for (i = 3; i <= 14; i++)
	{
		cin >> dp[i];
		dp[i] = min(min(dp[i - 1] + dp[i] * d, dp[i - 1] + m), dp[i - 3] + m3);
	}
	result = min(dp[14], y);
}

int main()
{
	cin >> T; t = 1;
	while (T--)
	{
		input(); cal();
		cout << "#" << t << " " << result << endl;
		t++;
	}
}