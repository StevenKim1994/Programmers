#include <iostream>

using namespace std;

int dp[60001];

int solution(int n)
{
	if (n == 1)
		return 1;

	else if (n == 2)
		return 2;

	else if (dp[n] > 0)
		return dp[n];
	
		dp[n] = (solution(n - 1) + solution(n - 2	)) % 1000000007;
	
	return dp[n];
}

int main()
{
	int n;
	cin >> n;

	cout << solution(n);


	return 0;
}