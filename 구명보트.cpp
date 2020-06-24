#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
	int answer = 0;
	int start = 0;
	int end = people.size() - 1;
	
	sort(people.begin(), people.end(), greater<int>()); // 내림차순 정렬

	while (true) // use runner method
	{
		if (start > end)
		{
			break; // 배에 타야할 남은 사람이 한명일때
		}
		if ( (people[start] + people[end]) <=limit)
			end--;

		start++;
		answer++;

	}

	return answer;
}


int main()
{
	int peopleNum, weightLimit;
	vector<int> peopleWeight;
	int inputData;
	

	cin >> peopleNum;

	for (int i = 0; i < peopleNum; i++)
	{
		cin >> inputData;		
		peopleWeight.push_back(inputData);
	}
	
	cin >> weightLimit;

	cout << solution(peopleWeight, weightLimit);

	return 0;
}