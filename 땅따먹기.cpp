#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
	int answer = 0;

	int maxIndex;
	int maxValue;

	for (int i = 0; i < land.size(); i++)
	{
		maxValue = *max_element(land[i].begin(), land[i].end());
		maxIndex = distance(land[i].begin(), find(land[i].begin(), land[i].end(), maxValue));

		// 이 다음 부터 maxIndex 번째 값 제외하고 최대값 찾아서 answer에 누적시키면된다. (만약 같은 줄에 같은 값이 없을 시에만 적용되는 규칙임) // 문제에서 같은 줄에 동일한 값이 나올수 있는지 언급이 안되어있음.. DP로 풀어야할듯

		if (i + 1 < land.size())
		{
			land[i + 1].erase(land[i + 1].begin() + maxIndex);
		}


		answer += maxValue;
	}

	return answer;
}


#if 0
int main()
{
	int N, inputData;
	vector<vector<int>> inputLand;
	cin >> N;

	for (int j = 0; j < N; j++)
	{
		vector<int> inputLandVector;
		for (int i = 0; i < 4; i++)
		{
			cin >> inputData;
			inputLandVector.push_back(inputData);
		}

		inputLand.push_back(inputLandVector);
	}
	
	cout << solution(inputLand) << endl;

	return 0;
}

#else

int sol(int n)
{
	if (n <= 0)
		return 0;

	return sol(n - 1) + sol(n);
}
int main()
{
	cout << sol(1) << endl;




}

#endif