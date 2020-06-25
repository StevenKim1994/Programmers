#include <iostream>

using namespace std;

int dp[10000000];

int solution(int n)
{
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] % 1234567) + (dp[i - 2] % 1234567);

	return dp[n] % 1234567;
}

int main()
{
	int input;

	cin >> input;
	cout << solution(input)<< endl;

	return 0;
}