#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, int number)
{
	int answer = 0;

	int dp[10];
	dp[0] = 2; // 0의 크기는 N-N 즉 N 2개로 만들 수 있음.
	dp[1] = 2; // ( N / N ) == 1
	dp[2] = 4;
	dp[N] = 1; // N의 크기는 자기자신 N 1개로 만들 수 있음.

	for (int i = 3; i < 10; i++)
		dp[i] = min(dp[i],dp[i - 1] + dp[i - 2]);
	
	if(number != N)
	{
		
	}
	else if(number == N)
	{
		answer = dp[N];
	}
	


	

	if (answer > 8) // 최소값이 8보다 크면 -1
		answer = -1;

	return answer;
}

int main()
{




	return 0;
}