#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;
	int size = priorities.size();
	int offset = 0;
	queue<int> myQueue;
	queue<int> resultQueue;
	for (int i = 0; i < size; i++)
	{
		int maxValue;
		if(priorities.size() > 0)
			maxValue = *max_element(priorities.begin(), priorities.end());
		
		for (int j = 0; j < priorities.size(); j++)
		{
			if (priorities[j] == maxValue)
			{
				if (myQueue.size() > 0)
				{
					// 맨 앞의 값을 빼고 맨뒤로 넣는다.
					int temp = myQueue.front();
					myQueue.pop();
					myQueue.push(j); // 새로 발견한 값의 인덱스를 큐에 push
					myQueue.push(temp);
				}
				else
					myQueue.push(j);
				
			}
		}
		
		for (vector<int>::iterator it = priorities.begin(); it != priorities.end();)
		{
			if (*it == maxValue)
			{
				it = priorities.erase(it); // 지울떄 해당 인덱스를 어떻게 처리해야할지 고민해야할듯??????
			
			}

			else
				it++;
		}

		while (true)
		{
			if (myQueue.size() == 0)
				break;

			resultQueue.push(myQueue.front());
			myQueue.pop();
		}
	
	}

	for (int i = 0; i < resultQueue.size(); i++)
	{
		// 해당 순서 서치
	}

	return answer;
}

int main()
{
	int printNum;
	vector<int> priorities;
	int location;
	int inputData;

	cin >> printNum;

	for (int i = 0; i < printNum; i++)
	{
		cin >> inputData;
		priorities.push_back(inputData);
	}

	cin >> location;

	cout << solution(priorities, location) << endl;

	return 0;
}