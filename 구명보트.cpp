#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
	int answer = 0;
	int currectLimit = limit;
	
	int start = 0;

	for (int i = people.size() - 1; i <= 0; i--)
	{
		
	}
	
	return answer+1;
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